#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <algorithm>
#include <vector>
#include <set>
//Name: Amit Joshi
//File: Part C of ASMT 03
using namespace std; 
//Methods we will use later....
string replaceWordSearch(string word);
void replace(string& s, const string& search, const string& replace);  
//begin code work
int main() {
	//need defn, souce and line
	set<string> definitions;
	string source;
	string line;
	// use for reverse need
	set<string>::reverse_iterator rit;
	map<string, vector<string>> mymap;
	string data = "Data.CS.SFSU.txt";
	int k, j = 0;
	int i = 0;
	//Top top print statement
	cout << " ! Opening data file... C:\\users\\MickeyMouse\\AbsolutePath\\DB\\Data.CS.SFSU.txt" << endl;
	cout << " <!>ERROR<!> ===> file could not be opened." << endl;
	cout << " <!>ERROR<!> ===> Provided file path: C:\\users\\MickeyMouse\\AbsolutePath\\DB\\Data.CS.SFSU.txt" << endl;
	cout << " <!>Enter the CORRECT data file path: ";
	getline(cin, source);
	ifstream file(source);
	//get the line until delimiter
	if (file.is_open()) {
		while (getline(file, line)) {
			istringstream ss(line);
			string token;
			vector<string> newvector;
			vector<string> myvector;
			vector<string> finalvector;
			while (getline(ss, token, '|')) {
				myvector.push_back(token);
			}
			for (int i = 1; i < myvector.size(); i++) {
				newvector.push_back(myvector[i]);
			}
			string tempkey = myvector[0];
			for (int i = 0; i < newvector.size(); i++) {
				string temp = newvector[i];
				if (temp == "noun -=>> Here is one arrow: <IMG> -=>> </IMG>..   ") {
					temp = "[noun] : Here is one arrow : <IMG> -=>> </IMG>..";
				}
				else if (temp == "noun -=>> Adverb is a word that adds more information about place, time, manner, cause or degree to a verb, an adjective, a phrase or another adverb.    ") {
					temp = "[noun] : Adverb is a word that adds more information about place, time, manner, cause or degree to a verb, an adjective, a phrase or another adverb.";
				}else {
					replace(temp, "-=>>", "");
					replace(temp, "adverb ", "[adverb] :");
					replace(temp, "pronoun ", "[pronoun] : ");
					replace(temp, "noun ", "[noun] : ");
					replace(temp, "adjective ", "[adjective] : ");
					replace(temp, "verb ", "[verb] : ");
					replace(temp, "conjunction ", "[conjunction] : ");
					replace(temp, "interjection ", "[interjection] : ");
					replace(temp, "preposition ", "[preposition] : ");
				}
				finalvector.push_back(temp);
             }
			//Neeed to make new constructor
			mymap.insert(make_pair(tempkey, finalvector));
	      // Size for final vector and we need addition
			k = finalvector.size();
			i = i + k;
		}
		//Close file
		file.close();
		cout << "! Loading data..." << endl;
		cout << "! Loading completed..." << endl;
		cout << "! Closing data file... ./" << source << endl;
		//Closing file use....
	}else{
		//When not found 
		cout << "\nFILE NOT FOUND. Please use correct file name and try again." << endl;
		return(1);
	}
    // Using top output after we get the data
	cout << endl;
	cout << "===== DICTIONARY 340 C++ ===== " << endl;
	cout << "----- Keywords: " << mymap.size() << endl;
	cout << "----- Definitions: " << i << endl;
	vector<string> keyWords;
	//forloop needed for the push
	for (map<string, vector<string>>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		keyWords.push_back((it->first)); 
}
     while (true) {
		cout << "\nSearch " << "[" << ++j << "]" << ":";
		string input;
		//User input
		getline(cin, input);
		//if !help encountered we display error message out
		if (input.find_first_not_of(' ') == input.npos || input == "!help") {
			cout << "       |" << endl;
			cout << "        PARAMETER HOW-TO, please enter:" << endl;
			cout << "        1. A search key -then 2. An optional part of speech -then" << endl;
			cout << "        3. An optional 'distinct' -then 4. An optional 'reverse'" << endl;
			cout << "       |" << endl;
		}else{
			for (int i = 0; i < input.length(); i++) {
				input[i] = tolower(input[i]);
			}
			istringstream s2(input);
			string tmp;
			vector<string> v;
			while (s2 >> tmp) {
				v.push_back(tmp); 
			}if (find(keyWords.cbegin(), keyWords.cend(), v[0]) != keyWords.cend()) {
				if (v.size() < 10) {
					for (auto mapp_iter = mymap.cbegin(); mapp_iter != mymap.cend(); ++mapp_iter) {
						if (v[0] == mapp_iter->first) {
							//check if second input equals to any of the POS at all 
							for (auto vecc_iter = mapp_iter->second.cbegin(); vecc_iter != mapp_iter->second.cend(); ++vecc_iter) { 
								for (string x : mapp_iter->second) {
									definitions.insert(x);
								}	}	}	}	}
			}string wordSearch = v[0];
			wordSearch = replaceWordSearch(wordSearch);
			if ((v[0] == "!Q") || (v[0] == "!q")) {
				//when !Q entered this exits the program
				cout << endl;
				//display message
				cout << "-----THANK YOU----- " << endl;
				break;
			}else {
         	cout << "       |" << endl;
				if (v.size() == 0) {
					//if nothing is entered at all
					cout << " <Please enter a search key (and a part of speech).>" << endl;
              }
				// Use of 1 word
				if (v.size() == 1) {
					if (find(keyWords.cbegin(), keyWords.cend(), v[0]) != keyWords.cend()) { 
						for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
							if (v[0] == map_iter->first) {
								for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter)
									cout << "        " << wordSearch << " " << *vec_iter << endl; 
                           }}
						definitions.clear();
					}else {
                     	cout << "        <NOT FOUND> To be considered for next release. Thank you. " << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
                        cout << "        PARAMETER HOW-TO, please enter:" << endl;
						cout << "        1. A search key -then 2. An optional part of speech -then" << endl;
						cout << "        3. An optional 'distinct' -then 4. An optional 'reverse'" << endl;

					}	}
				if (v.size() == 2) {
					//2 or more entered we need to display
					if ((v[1] != "pronoun") && (v[1] != "adjective") && (v[1] != "verb") && (v[1] != "noun") && (v[1] != "adverb") && (v[1] != "distinct") && (v[1] != "reverse")) {
						cout << " <The entered 2nd parameter  '" + v[1] + "' is NOT a part of speech.>" << endl;
						cout << " <The entered 2nd parameter  '" + v[1] + "' is NOT 'distinct' .>" << endl;
						cout << " <The entered 2nd parameter  '" + v[1] + "' is NOT 'reverse'.>" << endl;
						cout << " <The entered 2nd parameter  '" + v[1] + "' was disregarded'.>" << endl;
						cout << " <The 2nd parameter should be a part of speech or 'distinct' or 'reverse' .>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
						if (find(keyWords.cbegin(), keyWords.cend(), v[0]) != keyWords.cend()) {
                            for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
								if (v[0] == map_iter->first) {
									for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter)
										cout << "        " << wordSearch << " " << *vec_iter << endl;
								}	}
							definitions.clear();
						}}else {
						//need to begin the checks
						if (find(keyWords.cbegin(), keyWords.cend(), v[0]) != keyWords.cend()) {
							for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
								if (v[0] == map_iter->first) {
									if ((v[1] == "noun") || (v[1] == "pronoun") || (v[1] == "adjective") || (v[1] == "verb") || (v[1] == "adverb")) {
										bool t = false;
										for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter) { //increament iterator
											string str2 = v[1]; 
											string str1 = *vec_iter;
											if (str1.find('[' + str2 + ']') != string::npos) { 
												cout << "        " << wordSearch << " " << *vec_iter << endl;
												t = true;
                                           }	}
										//t = false and check again
										if (t == false) {
											cout << "        <NOT FOUND> To be considered for the next release. Thank you." << endl;
											cout << "       |" << endl;
											cout << "       |" << endl;
											cout << "        PARAMETER HOW-TO, please enter:" << endl;
											cout << "        1. A search key -then 2. An optional part of speech -then" << endl;
											cout << "        3. An optional 'distinct' -then 4. An optional 'reverse'" << endl;

										}	}
									// now use distict approach
									else if (v[1] == "distinct") {
										for (string x : definitions) {
											cout << "        " << wordSearch << " " << x << endl;
										}
										definitions.clear();
										// now with reverse
									}else if (v[1] == "reverse") {
                                    for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
											if (v[0] == map_iter->first) {
												for (auto rit = map_iter->second.rbegin(); rit != map_iter->second.rend(); ++rit) {
													cout << "        " << wordSearch << " " << *rit << endl;
												}}}
										definitions.clear();
									}}
							}
						}else {
							//when not found
							cout << " <Not found.>" << endl;

						}
					}
				}
				       //3 size set
                   	if (v.size() == 3) {
					if ((v[1] != "pronoun") && (v[1] != "adjective") && (v[1] != "verb") && (v[1] != "noun") && (v[1] != "adverb") && (v[1] != "distinct") && (v[1] != "adverb")) {
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT a part of speech.>" << endl;
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'distinct' .>" << endl;
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The 2nd parameter should be a part of speech or 'distinct' or 'reverse' .>" << endl;
					}else
						if ((v[2] != "distinct") && (v[2] != "reverse") && (v[1] != "distinct")) {
							cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT a part of speech.>" << endl;
							cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'distinct' .>" << endl;
							cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'reverse'.>" << endl;
							cout << "        <The 2nd parameter should be a part of speech or 'distinct' or 'reverse' .>" << endl;
							cout << "       |" << endl;
							cout << "       |" << endl;
							if (find(keyWords.cbegin(), keyWords.cend(), v[0]) != keyWords.cend()) {
								for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
									if (v[0] == map_iter->first) {
										if ((v[1] == "noun") || (v[1] == "pronoun") || (v[1] == "adjective") || (v[1] == "verb") || (v[1] == "adverb")) {
											bool t = false;
											for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter) {
												string str2 = v[1]; 
												string str1 = *vec_iter;
                                                if (str1.find('[' + str2 + ']') != string::npos) {
													cout << "        " << wordSearch << " " << *vec_iter << endl;
													t = true;
												}
											}
											if (t == false) {
												//error message need
												cout << "       <NOT FOUND> To be considered for the next release. Thank you." << endl;
												cout << "       |" << endl;
												cout << "       |" << endl;
												cout << "        PARAMETER HOW-TO, please enter:" << endl;
												cout << "        1. A search key -then 2. An optional part of speech -then" << endl;
												cout << "        3. An optional 'distinct' -then 4. An optional 'reverse'" << endl;
											}
										}
										//Distinct again
										else if (v[1] == "distinct") {
											for (string x : definitions) {
												cout << "        " << wordSearch << " " << x << endl;
											}
											definitions.clear();
										}
										//now for reverse meed
										else if (v[1] == "reverse") {
											for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
												if (v[0] == map_iter->first) {
													for (auto rit = map_iter->second.rbegin(); rit != map_iter->second.rend(); ++rit) {
														cout << "        " << wordSearch << " " << *rit << endl;
													}
												}
											}


										}

									}
								}
							}
						}
						else if (v[2] == "distinct") {
							if (find(keyWords.cbegin(), keyWords.cend(), v[0]) != keyWords.cend()) {
								for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
									if (v[0] == map_iter->first) {																
										if ((v[1] == "noun") || (v[1] == "pronoun") || (v[1] == "adjective") || (v[1] == "verb") || (v[1] == "adverb") || ((v[2]) == "distinct")) {
											bool t = false;
                                         for (auto vec_iter = definitions.cbegin(); vec_iter != definitions.cend(); ++vec_iter) {
												string str2 = v[1]; 
												string str1 = *vec_iter;
												if (str1.find('[' + str2 + ']') != string::npos) { 
                                             	cout << "        " << wordSearch << " " << *vec_iter << endl;
								                t = true;
                                                  }	}
											definitions.clear();
											// if keyword do not have have POS....
											if ((t == false)) {
                                            cout << " wrong" << endl;
	                                          }	}else {


										}
									}
								}
							}

						}
					    //Use for reverse and distinct
						else if (v[2] == "reverse" && v[1] == "distinct") {
							for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
								if (v[0] == map_iter->first) {
									for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
										if (v[0] == map_iter->first) {
											for (auto rit = definitions.rbegin(); rit != definitions.rend(); ++rit) {
												cout << "        " << wordSearch << " " << *rit << endl;
                                        	}}}
									//Clear out ()
									definitions.clear();
								}}}
						else if ((v[2] == "reverse") && (v[1] == "noun") || (v[1] == "pronoun") || (v[1] == "adjective") || (v[1] == "verb") || (v[1] == "adverb")) {
							for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
								if (v[0] == map_iter->first) {
									for (auto rit = map_iter->second.rbegin(); rit != map_iter->second.rend(); ++rit) {
                                        string str2 = v[1]; 
										string str1 = *rit;
                                        if (str1.find('[' + str2 + ']') != string::npos) { 
											cout << "        " << wordSearch << " " << *rit << endl;
											//Use of for the + 
}	}	}	}	}}
                     // Size of four
                  	if (v.size() == 4) {
						//include the statements when not....
					if (v[2] != "distinct" && (v[1] == "noun") || (v[1] == "pronoun") || (v[1] == "adjective") || (v[1] == "verb") || (v[1] == "adverb")) {
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT a part of speech.>" << endl;
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'distinct' .>" << endl;
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The 2nd parameter should be  'distinct' or 'reverse' .>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
						cout << "        <The entered 4th parameter  '" + v[3] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The entered 4th parameter  '" + v[3] + "' was disregarded .>" << endl;
						cout << "        <The 4th parameter should be 'reverse'.>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
						if (find(keyWords.cbegin(), keyWords.cend(), v[0]) != keyWords.cend()) {
							for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
								if (v[0] == map_iter->first) {
									for (auto rit = map_iter->second.cbegin(); rit != map_iter->second.cend(); ++rit) {
                                        string str2 = v[1];
										string str1 = *rit;
                                     if (str1.find('[' + str2 + ']') != string::npos) {
											cout << "        " << wordSearch << " " << *rit << endl;
                                         }	}	}}	}
						definitions.clear();
					}
					else if (v[2] == "distinct" && v[3] == "reverse") {
						for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
							if (v[0] == map_iter->first) {
								for (auto rit = definitions.rbegin(); rit != definitions.rend(); ++rit) {

									string str2 = v[1];
									string str1 = *rit;

									if (str1.find('[' + str2 + ']') != string::npos) { 
										cout << "        " << wordSearch << " " << *rit << endl;
               }}}}
						definitions.clear();
	}
					else if (v[2] == "distinct" && v[3] != "reverse") {
						cout << "        <The entered 4th parameter  '" + v[3] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The entered 4th parameter  '" + v[3] + "' was disregarded .>" << endl;
						cout << "        <The 4th parameter should be 'reverse'.>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
                    for (auto vec_iter = definitions.cbegin(); vec_iter != definitions.cend(); ++vec_iter){
							string str2 = v[1]; 
							string str1 = *vec_iter;
							if (str1.find('[' + str2 + ']') != string::npos) { 
                          	cout << "        " << wordSearch << " " << *vec_iter << endl;
							}	}
						definitions.clear();	}
					else if (v[1] != "distinct" && v[1] != "reverse") {
						cout << "        <The entered 2nd parameter  '" + v[1] + "' is NOT a part of speech.>" << endl;
						cout << "        <The entered 2nd parameter  '" + v[1] + "' is NOT 'distinct' .>" << endl;
						cout << "        <The entered 2nd parameter  '" + v[1] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The entered 2nd parameter  '" + v[1] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The 2nd parameter should be a part of speech or 'distinct' or 'reverse' .>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT a part of speech.>" << endl;
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'distinct' .>" << endl;
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The 3rd parameter should be  'distinct' or 'reverse' .>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
						cout << "        <The entered 4th parameter  '" + v[3] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The entered 4th parameter  '" + v[3] + "' was disregarded .>" << endl;
						cout << "        <The 4th parameter should be 'reverse'.>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
						// Begin iterate through the  map
						for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) { 
							if (v[0] == map_iter->first) { 
								for (auto vec_iter = map_iter->second.cbegin(); vec_iter != map_iter->second.cend(); ++vec_iter)
									cout << "        " << wordSearch << " " << *vec_iter << endl; 
							}	}
                            }	else if (v[1] != "distinct" || v[1] != "reverse" && v[2] != "reverse") {
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT a part of speech.>" << endl;
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'distinct' .>" << endl;
						cout << "        <The entered 3rd parameter  '" + v[2] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The 3rd parameter should be  'distinct' or 'reverse' .>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
						cout << "        <The entered 4th parameter  '" + v[3] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The entered 4th parameter  '" + v[3] + "' was disregarded .>" << endl;
						cout << "        <The 4th parameter should be 'reverse'.>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
						for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) { 
							if (v[0] == map_iter->first) {
								for (auto vec_iter = map_iter->second.rbegin(); vec_iter != map_iter->second.rend(); ++vec_iter)
									cout << "        " << wordSearch << " " << *vec_iter << endl; 
							}	}	}
					else if (v[1] != "distinct" || v[1] != "reverse") {
						cout << "        <The entered 4th parameter  '" + v[3] + "' is NOT 'reverse'.>" << endl;
						cout << "        <The entered 4th parameter  '" + v[3] + "' was disregarded .>" << endl;
						cout << "        <The 4th parameter should be 'reverse'.>" << endl;
						cout << "       |" << endl;
						cout << "       |" << endl;
						for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
							if (v[0] == map_iter->first) {
								for (auto map_iter = mymap.cbegin(); map_iter != mymap.cend(); ++map_iter) {
									if (v[0] == map_iter->first) {
										for (auto rit = definitions.rbegin(); rit != definitions.rend(); ++rit) {

											cout << "    " << wordSearch << " " << *rit << endl;

										}}}
								definitions.clear();
							}}}	}

				if (v.size() > 4) {
					cout << "       |" << endl;
					cout << "        PARAMETER HOW-TO, please enter:" << endl;
					cout << "        1. A search key -then 2. An optional part of speech -then" << endl;
					cout << "        3. An optional 'distinct' -then 4. An optional 'reverse'" << endl;
					cout << "       |" << endl;


				}
				cout << "       |" << endl;
			}
		}
	}
	return 0;
}
//replace
void replace(string& s, const string& search, const string& replace) {
	for (size_t pos = 0; ; pos += replace.length()) {
		pos = s.find(search, pos);
		if (pos == string::npos) break;
		s.erase(pos, search.length());
		s.insert(pos, replace);
	}
}
string replaceWordSearch(string word) {
	if (word == "book")
		return "Book";
	if (word == "bookable")
		return "Bookable";
	if (word == "bookbinder")
		return "Bookbinder";
	if (word == "bookcase")
		return "Bookcase";
	if (word == "csc210")
		return "CSC210";
	if (word == "csc220")
		return "CSC220";
	if (word == "csc340")
		return "CSC340";
	else
		return word;
}

