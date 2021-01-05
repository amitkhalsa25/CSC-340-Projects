import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.*;
//Name: Amit Joshi
//Student Id:918210532
//Begin with enum
public enum Dictionary{
    //Enum 3 String Constructors
    BOOK("book", "noun", "A set of pages."),
    BOOK1("book", "noun", "A written work published in printed or electronic form."),
    BOOK2("book", "verb", "To arrange for someone to have a seat on a plane."),
    BOOK3("book", "verb", "To arrange something on a particular date."),
    ARROW("arrow", "noun", "Here is one arrow: <IMG> -=>> </IMG>"),
    DISTINCT("distinct", "adjective", "Familiar. Worked in Java."),
    DISTINCT1("distinct", "adjective", "Unique. No duplicates. Clearly different or of a different kind"),
    DISTINCT2("distinct", "adverb", "Uniquely. \" Written distinctly \""),
    DISTINCT3("distinct", "noun", "A keyword in this assignment."),
    DISTINCT4("distinct", "noun", "A keyword in this assignment."),
    DISTINCT5("distinct", "noun", "A keyword in this assignment."),
    DISTINCT6("distinct", "noun", "An advanced search option."),
    DISTINCT7("distinct", "noun", "Distinct is a parameter in this assignment."),
    PLACEHOLDER("placeholder", "adjective", "To be updated..."),
    PLACEHOLDER1("placeholder", "adjective", "To be updated..."),
    PLACEHOLDER2("placeholder", "adverb", "To be updated..."),
    PLACEHOLDER3("placeholder", "conjunction", "To be updated..."),
    PLACEHOLDER4("placeholder", "interjection", "To be updated..."),
    PLACEHOLDER5("placeholder", "noun", "To be updated..."),
    PLACEHOLDER6("placeholder", "noun", "To be updated..."),
    PLACEHOLDER7("placeholder", "noun", "To be updated..."),
    PLACEHOLDER8("placeholder", "preposition", "To be updated..."),
    PLACEHOLDER9("placeholder", "pronoun", "To be updated..."),
    PLACEHOLDER10("placeholder", "verb", "To be updated..."),
    REVERSE("reverse","adjective","On back side."),
    REVERSE1("reverse","adjective","Opposite to usual or previous arrangement"),
    REVERSE2("reverse","noun","A dictionary program's parameter"),
    REVERSE3("reverse","noun","The opposite."),
    REVERSE4("reverse","noun","To be updated."),
    REVERSE5("reverse","noun","To be updated."),
    REVERSE6("reverse","noun","To be updated."),
    REVERSE7("reverse","noun","To be updated."),
    REVERSE9("reverse","verb","Change something to opposite."),
    REVERSE10("reverse","verb","Go Back."),
    REVERSE11("reverse","verb","Revoke ruling."),
    REVERSE12("reverse","verb","To be updated."),
    REVERSE13("reverse","verb","To be updated."),
    REVERSE14("reverse","verb","Turn something inside out."),
    SOMETHING1("something","adverb","To be updated"),
    SOMETHING2("something","noun","To be updated"),
    SOMETHING3("something","noun","To be updated"),
    SOMETHING4("something","noun","To be updated"),
    SOMETHING5("something","verb","To be updated"),
    Hi("Hi","verb","To say Hi"),
    GAMER("Gamer","verb","to play games"),
    Xbox360("Xbox","verb","to play "),
    XboxOne("Xbox","verb","to play games"),
    XboxX("Xbox","verb","to play games"),
    Ps4("PS4", "noun", "To be updated."),
    PS5("PS5", "noun", "To be updated."),
    Number("Number", "noun", "To be updated."),
    Earth("Earth", "noun", "To be updated."),
    Randomword1("emoji", "noun", "To be updated."),
    Randomword2("celebration", "noun", "To be updated."),
    Randomword3("desktop", "noun", "To be updated."),
    Randomword4("earth", "noun", "To be updated."),
    Randomword5("mars", "noun", "To be updated."),
    Randomword6("planets", "noun", "To be updated."),
    Religion("Religion", "noun", "To be updated."),
    World1("World", "noun", "To be updated."),
    WORLD2("World", "noun", "To be updated.");
    // Set my variables up definition, word, partOfSpeech!
    private String definition;
    private String partOfSpeech;
    private String word;
    // Dictionary Constructor include the variables up top.
    private Dictionary(String word, String partOfSpeech, String definition){
        this.word = word;
        this.partOfSpeech = partOfSpeech;
        this.definition = definition;
    }
    public String getPartOfSpeech() {
        return this.partOfSpeech;
    }
    //Make new
    // Use toUpperCase() delete if not working
    public String getWord() {
        return this.word.toUpperCase();
    }
    public String getDefinition() {
        return this.definition;
    }
    @Override
    public String toString(){
        return this.word + " [" + this.partOfSpeech + "] : " + this.definition;
    }
    public static void main(String[] args) {
        //Input Scanner for user and also definitionNum set = 0;
        int definitionNumber=0;
        Scanner input = new Scanner(System.in);
        System.out.println("! Loading data...");
        //Make hashMap to store dictionary enum values
        HashMap<String, ArrayList<Dictionary>> hashMap = new HashMap<String, ArrayList<Dictionary>>();
        for (Dictionary dictionary : Dictionary.values()) {
            String word = dictionary.getWord();
            ArrayList<Dictionary> details = (hashMap.containsKey(word)) ? hashMap.get(word) : new ArrayList<Dictionary>();
            details.add(dictionary);
            Collections.sort(details, new Sort());
            hashMap.put(word, details);
            //Counter needed
            definitionNumber++;
        }
        //Top Top part of the output we need! Include extra space at bottom.
        System.out.println("! Loading Complete...");
        System.out.println();
        System.out.println("===== Dictionary 340 JAVA ======");
        System.out.println("----- Keywords: " + hashMap.size());
        System.out.println("----- Definitions: " + definitionNumber);
        System.out.println();
        Boolean quit = true;
        int searchCount=0;
        do {
            searchCount++;
            //User input
            System.out.print("Search " + "[" + searchCount + "]: ");
            String userinput = input.nextLine();
            String[] split = userinput.split(" ");
            String word = null;
            Boolean requestDistinct = false;
            Boolean requestReverse = false;
            String partOfSpeech = null;
            if (split.length > 0){
                word = split[0];
            }
            // All of part of speeches
            String[] partOfSpeeches = {"noun", "verb", "adjective", "adverb", "pronoun", "preposition", "conjunction", "interjection"};
            if (split.length > 4){
                ////Prints menu when nothing is entered
                printMenu();
                //Pass on ahead
                continue;
            }
            //Another check and create if statements and check out for the words.
            //Calls in distinct method if user enters exactly "distinct"
            if (split.length > 1 && split[1]!= null){
                if (split[1].equalsIgnoreCase("distinct")){
                    requestDistinct = true;
                }
                //Calls in reverse method when user enters "reverse"
                else if (split[1].equalsIgnoreCase("reverse")){
                    requestReverse = true;
                }
                else if (Arrays.asList(partOfSpeeches).contains(split[1].toLowerCase())){
                    partOfSpeech = split[1];
                } else {
                    System.out.println("   |");
                    System.out.println("    <The entered 2nd parameter '" + split[1] + "' is NOT a part of speech.>\n" +
                            "    <The entered 2nd parameter '" + split[1] + "' is NOT 'distinct'.>\n" +
                            "    <The entered 2nd parameter '" + split[1] + "' is NOT 'reverse'.>\n" +
                            "    <The entered 2nd parameter '" + split[1] + "' was disregarded.>\n" +
                            "    <The 2nd parameter should be a part of speech or 'distinct' or 'reverse'.>");
                    System.out.println("   |");
                } }
            //When the user inputs more than 2 words in the user input, program checks if you need to call in distinct, reverse, or part of speeches methods as well!
            if (split.length > 2 && split[2]!= null){
                //Calls in distinct method we use
                if (split[2].equalsIgnoreCase("distinct")){
                    requestDistinct = true;
                }
                //Calls in reversed method we use
                else if (split[2].equalsIgnoreCase("reverse")){
                    requestReverse = true;
                }
                // part of speeches call in
                else if (Arrays.asList(partOfSpeeches).contains(split[2].toLowerCase())){
                    partOfSpeech = split[2];
                }else{
                    System.out.println("   |");
                    System.out.println("    <The entered 3rd parameter '" + split[2] + "' is NOT 'distinct'.>\n" +
                            "    <The entered 3rd parameter '" + split[2] + "' is NOT 'reverse'.>\n" +
                            "    <The entered 3rd parameter '" + split[2] + "' was disregarded.>\n" +
                            "    <The 3rd parameter should be 'distinct' or 'reverse'.>");
                    System.out.println("   |");
                } }
            //Create the reverse check statement condition!
            ////Checks if the 4th word is reverse and calls it in if it is.
            if (split.length > 3 && split[3]!= null){
                if (split[3].equalsIgnoreCase("reverse")) {
                    requestReverse = true;
                }else{
                    System.out.println("   |");
                    System.out.println("    <The entered 4th parameter '" + split[3] + "' is NOT 'reverse'.>\n" +
                            "    <The entered 4th parameter '" + split[3] + "'  was disregarded.>\n" +
                            "    <The 4th parameter should be 'reverse'.>");
                    System.out.println("   |");
                }
            }
            //!q quit of the program and if statements on the results or if not found
            if(!userinput.equalsIgnoreCase("!q")) {
                ArrayList<Dictionary> result = hashMap.get(word.toUpperCase());
                ArrayList<Dictionary> secondResult = (requestDistinct) ? returnDictionaryWithDistinct(result) : result;
                ArrayList<Dictionary> thirdResult = (partOfSpeech != null) ? returnDictionaryWithSamePartOfSpeech(secondResult, partOfSpeech) : secondResult;
                ArrayList<Dictionary> fourthResult = (requestReverse) ? returnDictionaryWithReverse(thirdResult) : thirdResult;
                if (fourthResult != null && fourthResult.size() > 0) {
                    System.out.println("   |");
                    for (Dictionary key : fourthResult) {
                        System.out.print("    " + key + "\n");
                    }
                    System.out.println("   |");
                } else if (userinput.equals("!help") || userinput.equals(" ") || userinput.equals("")) {
                    printMenu();
                } else {
                    System.out.println("   |");
                    System.out.println("    <NOT FOUND> To be considered for the next release. Thank you.");
                    System.out.println("   |");
                    printMenu();
                } }
            // Else program ends
            else{
                System.out.println("\n---- THANK YOU ----");
                quit = false;
            }
        } while(quit);
        input.close();
        //Closed for user input
    }
    // This prints out the home menu
    public static void printMenu(){
        System.out.println("   |");
        System.out.println("    PARAMETER HOW-TO, please enter:\n" +
                "    1. A search key -then 2. An optional part of speech -then\n" +
                "    3. An optional 'distinct' -then 4. An optional 'reverse'");
        System.out.println("   |");
    }
    //Return Dictionary with same part of speech method.
    public static ArrayList<Dictionary> returnDictionaryWithSamePartOfSpeech(ArrayList<Dictionary> dictList, String partOfSpeech) {
        ArrayList<Dictionary> result = new ArrayList<Dictionary>();
        if (dictList != null)
        {
            for(Dictionary dict : dictList)
            {
                if (dict.getPartOfSpeech().equalsIgnoreCase(partOfSpeech)){
                    result.add(dict);
                } } }
        return result;
    }
    //Dictionary with reverse method and sees conditions of what's happening.
    public static ArrayList<Dictionary> returnDictionaryWithReverse(ArrayList<Dictionary> dictionaryList){
        ArrayList<Dictionary> result = new ArrayList<Dictionary>();
        if (dictionaryList != null) {
            for(Dictionary dictionary : dictionaryList) {
                result.add(dictionary);
            }
            Collections.reverse(result);
        }
        return result;
    }
    //Make Conditions for the Distinct
    public static ArrayList<Dictionary> returnDictionaryWithDistinct(ArrayList<Dictionary> dictionaryList) {
        HashMap<String, ArrayList<Dictionary>> hewHashMap = new HashMap<String, ArrayList<Dictionary>>();
        ArrayList<Dictionary> result = new ArrayList<Dictionary>();
        for(Dictionary dictionary : dictionaryList){
            String partOfSpeech = dictionary.getPartOfSpeech();
            Boolean hasDuplicate = false;
            if(hewHashMap.containsKey(partOfSpeech)) {
                for(Dictionary dictionary1 : hewHashMap.get(partOfSpeech)){
                    if (dictionary1.getDefinition().equals(dictionary.getDefinition())){
                        hasDuplicate = true;
                    }}
                if(!hasDuplicate){
                    hewHashMap.get(partOfSpeech).add(dictionary);
                }
            } else{
                ArrayList<Dictionary> tempResult = new ArrayList<Dictionary>();
                tempResult.add(dictionary);
                hewHashMap.put(partOfSpeech, new ArrayList<Dictionary>(tempResult));
            }
        }
        for(ArrayList<Dictionary> values : hewHashMap.values()){
            result.addAll(values);
        }
        Collections.sort(result, new Sort());
        return result;
    }}
//Made compare method that compares parts of speeches and return defnition
class Sort implements Comparator<Dictionary>{
    public int compare(Dictionary a,Dictionary b){
        if(a.getPartOfSpeech().compareTo(b.getPartOfSpeech())==0){
            return a.getDefinition().compareTo(b.getDefinition());
        }
        return a.getPartOfSpeech().compareTo(b.getPartOfSpeech());
    }
    //end
}
//End of program :))
