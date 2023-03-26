#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***************************************************************************************/
/* Program name:  Magic-8ball.c                                                        */         
/* Program purpose: To simulate a Magic 8ball for fun                                  */
/* Date created:  Sunday, March 26th, 2023 (3/26/2023)                                 */
/* Program Author: Zian Elijah Smith                                                   */
/*                                                                                     */
/* Compile Options:                                                                    */
/*                                                                                     */
/* clang -std=gnu17 -W -Wall -O -fsanitize=address,undefined magic-8ball.c -o          */
/*                                                                                     */
/* gcc -std=gnu17 -W -Wall -O -fsanitize=address,bounds-strict magic-8ball.c -o test   */
/***************************************************************************************/

int main(void)
{
    /* Responses are based on a random number */
    /* The random number will access an index */
    /* We use 0 to 20, because the array has  */
    /* 20 items, that way, all items are      */
    /* possible                               */

    // Declare constants!
    int LOWEST_LIMIT;
    int HIGHEST_LIMIT;
    // Define constants! :D
    LOWEST_LIMIT = 0;
    HIGHEST_LIMIT = 20;
    
    
    // Define array of responses
    // Source for responses: https://en.wikipedia.org/wiki/Magic_8_Ball#Possible_answers
    const char *array_of_responses[500] = {
    "It is certain.", "It is decidedly so.", "Without a doubt.", "Yes definitely.", \
    "You may rely on it.", "As I see it, yes.", "Most likely.", "Outlook good.", \
    "Yes.", "Signs point to yes.", "Reply hazy, try again.", " Ask again later.", \
    "Better not tell you now.", "Cannot predict now.", "Concentrate and ask again." \
    "Don't count on it.", "My reply is no.", "My sources say no.", \
    "Outlook not so good.", "Very doubtful. " \
     };
     
    // Magic number will determine the response from the array!
    int magic_number;
    
    srand(time(NULL));
    
    // Make a random number
    magic_number = (rand() % (HIGHEST_LIMIT - LOWEST_LIMIT + 1)) + LOWEST_LIMIT;
    
    // Request user asks a question!
    printf("Please ask your question!\n");

    // Take user input! 
    // Want to use the response 
    // to help seed the random number determined later
    // don't know how yet
    char user_input[500];
    
    // Don't use this, gives warnings due to types
    // scanf("%[^\n]s", &user_input);
    // Don't use this, will give memory issue
    // scanf("%[^\n]s", user_input);
    
    // use this, tells starting point of array and etc
    scanf("%[^\n]s", &user_input[0]);
    
    // print response!
    printf("%s\n", array_of_responses[magic_number]);
    printf("Your question was.... '%s'\n", user_input);
    


    // Return EXIT_SUCCESS if everything is all good
    return EXIT_SUCCESS;
}

// got zero errors and zero warnings with.....
// gcc -std=gnu17 -W -Wall -O -fsanitize=address,bounds-strict magic-8ball.c -o test
// on Debian 10 buster 64 bit

