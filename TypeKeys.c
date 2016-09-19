/*
 Author: Hubert Plewa
 Program #2: Type Keys
 
 9/9/2016
 */

#include <stdio.h>
#include <string.h>

const int MAX_LINE_LENGTH = 81;


/*Enter the text file name here*/
const char fileName[] = "20000LeaguesUnderTheSeaJulesVerne.txt";
/*Enter the text file name here*/


void extractNextWordFromLine(
                             char allWords[],    // The line of all words
                             int *wordsIndex,    // The current index postion in allWords, with changes reflected back
                             char newWord[])     // The new word is placed in this array, to be returned and used
{
    int j = 0;     // Set the index within the newWord array to start at the beginning
    char c='\0';   // Temporary storage for each character as we read it
    
    // Initialize c to be the first character, if there is one
    if( allWords[ *wordsIndex] != '\0') {
        c = allWords[ *wordsIndex];     // Get first character
        (*wordsIndex)++;                // Advance index to the next character
    }
    
    // Skip leading spaces if there are any
    while( c==' ') {
        c = allWords[ *wordsIndex];   // advance to the next character
        (*wordsIndex)++;              // Advance index to the next character
    }
    
    // Copy characters into the word until we hit a space or null
    while( c!=' ' && c!='\0') {
        newWord[ j++] = c;
        // Get the next character
        c = allWords[ *wordsIndex];
        // advance to the next character if we're not at the end of the list
        if( c!='\0') {
            (*wordsIndex)++;          // Advance index to the next character
        }
    }//end while(...
    
    // NULL terminate the word so that we can use string functions
    newWord[ j] = '\0';
}


double CountQWERTYHomeRowChars(char word[]){
    
    double qHomeRowChar = 0.0;
    int i;
    
    char homeRowLetter[] = "aA sS dD fF gG hH jJ kK lL ;: '\"";
    
    for(i=0;i<strlen(word);i++){
        if(strchr(homeRowLetter,word[i])){
            qHomeRowChar++;
        }
    }
    return qHomeRowChar;
}

/*If word contains non-homerow alphanumeric character, return 0.
 Else return 1 to increment QWERTY homerow word counter in main*/
double CountQWERTYHomeRowWords(char word[]){
    
    int i = 0;
    
    char notHomeRowLetter[] = "qQ wW eE rR tT yY uU iI oO pP zZ xX cC vV bB nN mM 1234567890";
    
    for(i=0;i<strlen(word);i++){
        if(strchr(notHomeRowLetter,word[i])){
            return 0;
        }
    }
    return 1;
}


double CountQWERTYDistance(char word[]) {
    
    double qDistance = 0.0;
    int k = 0;
    
    
    char zero[] = "aA sS dD fF jJ kK lL ;:";
    
    char pointSeventyFive[]="qQ wW eE rR uU iI oO pP gG hH zZ xX cC vV nN mM ,<.>/?\'\"";
    
    char one[] = "tT yY [{";
    
    char onePointTwentyFive[] = "bB ]}";
    
    char onePointFive[] = "1! 2@ 3# 4$ 5% 7& 8* 9( 0) -_ =+ \\|";
    
    char onePointSeventyFive[] = "`~ 6^";
    
    
    for(k = 0;k < strlen(word); k++) {
        
        if(strchr(zero,word[k])){
            qDistance += 0.0;
        }

        else if(strchr(pointSeventyFive,word[k])){
            qDistance += 0.75;
        }
        
        else if(strchr(one,word[k])){
            qDistance += 1.0;
        }
        
        else if(strchr(onePointTwentyFive, word[k])){
            qDistance += 1.25;
        }
        
        else if(strchr(onePointFive,word[k])){
            qDistance += 1.5;
        }
        
        else if(strchr(onePointSeventyFive,word[k])){
            qDistance += 1.75;
        }
        
        else {
            qDistance += 0;
            //printf("QWERTY DISTANCE ADD ME: %c\n", word[k]);
        }
    }
    return qDistance;
}


double CountQWERTYLeftHandWords(char word[]){
    
    char rightHandLetters[] = "yY uU iI oO pP hH jJ kK lL ;: \'\" nN mM,<.>/?-_=+[{]}|\\7&8*9\(0)";
    int i;
    for(i=0;i<strlen(word);i++){
        if(strchr(rightHandLetters,word[i])){
            return 0;
        }
    }
    return 1;
}


double CountQWERTYRightHandWords(char word[]){
    
    char leftHandLetters[] = "qQ wW eE rR tT aA sS dD fF gG zZ xX cC vV `~ 1! 2@ 3# 4$ 5% 6^";
    int i;
    for(i = 0; i<strlen(word);i++){
        
        if(strchr(leftHandLetters,word[i])) {
            return 0;
        }
    }
    return 1;

}

/*If word contains non-homerow alphanumeric character, return 0.
 Else return 1 to increment DVORAK homerow word counter in main*/
double CountDVORAKHomeRowWords(char word[]){
    
    char notHomeRowLetter[] = "pP yY fF gG cC rR lL qQ jJ kK xX bB mM wW vV zZ 1234567890";
    int i;
    
    for(i=0;i<strlen(word);i++){
        
        if(strchr(notHomeRowLetter,word[i])){
            return 0;
        }
    }
    return 1;

}


double CountDVORAKHomeRowChars(char word[]){
    
    double dHomeRowChar = 0.0;
    int i;
    
    char homeRowChars[] = "aA oO eE uU iI dD hH tT nN sS -_";
    
    for (i=0;i<strlen(word);i++){
        if(strchr(homeRowChars,word[i])){
            dHomeRowChar++;
        }
    }
    return dHomeRowChar;
}


double CountDVORAKDistance(char word[]){
    
    double dDistance = 0.0;
    int k = 0;
    
    char zero[] = "aA oO eE uU hH tT nN sS";
    
    char pointSeventyFive[]="\' \" ,< .> pP gG cC rR lL ;: qQ jJ kK bB mM wW vV zZ iI dD -_";
    
    char one[] = "yY fF /?";
    
    char onePointTwentyFive[] = "xX";
    
    char onePointFive[] = "1! 2@ 3# 4$ 5% 7& 8* 9( 0) [{ ]}";
    
    char onePointSeventyFive[] = "`~ 6^";
    
    for(k=0;k<strlen(word);k++) {
        
        if(strchr(zero,word[k])){
            dDistance += 0.0;
        }
        
        else if(strchr(pointSeventyFive,word[k])){
            dDistance += 0.75;
        }

        else if(strchr(one,word[k])){
            dDistance += 1.0;
        }
        
        else if(strchr(onePointTwentyFive,word[k])){
            dDistance += 1.25;
        }
        
        else if(strchr(onePointFive,word[k])){
            dDistance += 1.5;
        }

        else if(strchr(onePointSeventyFive,word[k])){
            dDistance += 1.75;
        }
        
        else {
            dDistance += 0.0;
            //printf("DVORAK DISTANCE ADD ME: %c\n", word[k]);
        }
    }
    return dDistance;
}


double CountDVORAKLeftHandWords(char word[]){
    
    char rightHandLetter[] = "fF gG cC rR lL /? =+ \\| dD hH tT nN sS -_ bB mM wW vV zZ 7&8*9(0)[{]}";
    int i;
    for(i = 0; i<strlen(word); i++){
        
        if(strchr(rightHandLetter,word[i])){
            return 0;
        }
    }
    return 1;
}


double CountDVORAKRightHandWords(char word[]){
    
    char leftHandLetters[] = "\\| ,< .> pP yY aA oO eE uU iI ;: qQ jJ kK `~ 1!2@3#4$5%";
    int i;
    for (i = 0; i<strlen(word);i++){
        if(strchr(leftHandLetters,word[i])){
            return 0;
        }
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    
    printf("Author: Hubert Plewa\n");
    printf("Class: CS141\n");
    printf("Program #2: Type Keys\n");
    printf("TA: Nilanjana Basu, Tuesday 9-10\n");
    printf("9/9/2016\n");
    
    FILE *inFile;
    
    inFile = fopen(fileName, "r");
    
    if (inFile == NULL) {
        printf("Couldn't open %s.\n", fileName);
        return -1;
    }
    printf("\n");
    //printf("Opening file %s.\n", fileName);
    //printf("\n");
    printf("Reading first two lines.\n");
    
    char line[MAX_LINE_LENGTH];
    char word[MAX_LINE_LENGTH];

    int i = 0;
    int j = 0;
    int charCount = 0;
    int wordCount = 0;
    
    double qHomeRowWords = 0.0;
    double qHomeRowChar = 0.0;
    double qDistance = 0.0;
    double qOneHandWord = 0.0;

    double dHomeRowWords = 0.0;
    double dHomeRowChar = 0.0;
    double dDistance = 0.0;
    double dOneHandWord = 0.0;
    
    /*Prints lines 1 for each loop*/
    while (fgets(line, MAX_LINE_LENGTH, inFile)) {
        
        /*ends line read*/
        line[ strlen(line)-1] = '\0';
        
        //printf("Individual words: \n");
        
        i=0;        // This must be reset each time a new line is processed
        while( line[ i] != '\0') {
            
            extractNextWordFromLine( line, &i, word);
            
            //printf("%s\n", word);
            
            if (word[0] != '\0' || word[0] != ' ' || word[0] != '\n'){
                
                wordCount++;
                
                /*Increment QWERTY homerow letter count*/
                qHomeRowChar += CountQWERTYHomeRowChars(word);
                
                /*If the word contains a non-QWERTY-homerow letter, get the next word
                  Else increment QWERTY HOMEROW word count*/
                qHomeRowWords += CountQWERTYHomeRowWords(word);
                
                /*Counting DISTANCE traveled for QWERTY*/
                qDistance += CountQWERTYDistance(word);
                
                /*Counting QWERTY words typed with LEFT hand*/
                qOneHandWord += CountQWERTYLeftHandWords(word);

                /*Counting QWERTY words typed with RIGHT hand*/
                qOneHandWord += CountQWERTYRightHandWords(word);
                
                
                /*Increment DVORAK HOMEROW letter count*/
                dHomeRowChar += CountDVORAKHomeRowChars(word);

                /*If the word contains a non-DVORAK-homerow letter, get the next word
                 Else increment DVORAK HOMEROW word count*/
                dHomeRowWords += CountDVORAKHomeRowWords(word);
                
                /*Counting DISTANCE traveled for DVORAK*/
                dDistance += CountDVORAKDistance(word);
                
                /*Counting DVORAK words typed with LEFT hand*/
                dOneHandWord += CountDVORAKLeftHandWords(word);
                
                /*Counting DVORAK words typed with RIGHT hand*/
                dOneHandWord += CountDVORAKRightHandWords(word);

                //Counting characters
                charCount += strlen(word);
                
            }//end if word[0] != invalid char
            
        }//End while line != \0
        
        /*Printing lines 1 and 2*/
        if(j < 2) {
            printf("%s\n", line);
            j++;
        }
    
    }/*End While Loop*/
    
    printf("\n");
    printf("               Total words: %d\n",wordCount);
    printf("Total non-blank characters: %d\n", charCount);
    printf("\n");
    printf("                             Qwerty  Dvorak\n");
    
    printf("%% All Characters on home row:   %.lf%%     %.lf%%\n",
           (qHomeRowChar/charCount) * 100, (dHomeRowChar/charCount)*100);
    
    printf("     %% All words on home row:    %.lf%%     %.lf%%\n",
           (qHomeRowWords/wordCount)*100,(dHomeRowWords/wordCount)*100);
    
    printf("   %% Words typed on one hand:   %.lf%%     %.lf%%\n",
           (qOneHandWord/wordCount)*100, (dOneHandWord/wordCount)*100);
    
    printf("   Distance travelled(miles): %.3lf   %.3lf\n",
           (qDistance/(12*5280)),(dDistance/(12*5280)));
    
    
//    printf(" All Characters on home row:   %.lf     %.lf\n",
//           qHomeRowChar, dHomeRowChar);
//    
//    printf("      All words on home row:    %.lf     %.lf\n",
//           qHomeRowWords,dHomeRowWords);
//    
//    printf("    Words typed on one hand:   %.lf     %.lf\n",
//           qOneHandWord, dOneHandWord);
//    
//    printf("   Distance travelled(inches): %.lf   %.lf\n",
//           qDistance,dDistance);

    //printf("Closing file %s.\n", fileName);
    fclose(inFile);
    
    return 0;
}
