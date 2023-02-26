/*
 *  CSC A48 - Winter 2023 - Assignment 1 starter
 * 
 *  (c) 2020-23 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring 
 * questions to your TAs or instructors during office hours. Please
 * remember:
 * 
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name): Shekhtman, Sean
 * Student Number: 1008305371
 * UTORid: schekhtm
 * Your instructor's name is: Paco Estrada
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name: Sean Shekhtman
 *
 *  
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{    
    char name[MAX_STR_LEN];
    float salary;

    struct castList_struct *next;
    
} CastList;

typedef struct movieReview_struct
{
    char movie_title[MAX_STR_LEN];
    char movie_studio[MAX_STR_LEN];
    int year; /* b/w 1920-2999 */ 
    float BO_total;
    int score; /* b/w 0-100 */

    CastList *cast;
    
} MovieReview;

typedef struct reviewNode_struct
{
    MovieReview review;
    struct reviewNode_struct *next;
    
} ReviewNode;

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  scoreList = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_node=NULL;
    new_node = (ReviewNode *)calloc(1, sizeof(ReviewNode));

    if (new_node == NULL) return NULL; // No more space!

    strcpy(new_node->review.movie_title, "");
    strcpy(new_node->review.movie_studio, "");
    new_node->review.year = -1;
    new_node->review.BO_total = -1;
    new_node->review.score = -1;
    new_node->review.cast = NULL;
    new_node->next = NULL;
    
    return new_node;    
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * The movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p = NULL;
    p = head;

    while (p != NULL){
        if ((strcmp(p->review.movie_title, title) == 0 &&
            strcmp(p->review.movie_studio, studio) == 0 &&
            p->review.year == year)) return p; // Key found!

        p = p->next;
    }
    
    return NULL;  // Key not found... :(
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    if (findMovieReview(title, studio, year, head) != NULL) return head; // Duplicate Found!

    ReviewNode *new_node = NULL;
    new_node = newMovieReviewNode();
    if (new_node == NULL) return NULL; // Check for space!

    strcpy(new_node->review.movie_title, title);
    strcpy(new_node->review.movie_studio, studio);
    new_node->review.year = year;
    new_node->review.BO_total = BO_total;
    new_node->review.score = score;
    new_node->next = head;

    return new_node;
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews. 
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
    ReviewNode *p = NULL;
    p = head;
    unsigned int n = 0;

    while (p != NULL){
        p = p->next;
        n++;
    }
    return n;
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p = NULL;
    p = findMovieReview(title, studio, year, head);

    if (p == NULL){
        printf("Sorry, no such movie exists in the database");
        return;
    }

    p->review.BO_total = BO_total;
    p->review.score = score;
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    if (head == NULL) return NULL;

    ReviewNode *desired_movie = NULL;
    desired_movie = findMovieReview(title, studio, year, head);

    if (desired_movie == NULL) return head; // Movie not Found! After this, we know the desired_movie exists.

    ReviewNode *q = NULL;
    q = head->next;

    if (desired_movie == head){
        // Head Deletion
        free(desired_movie);
        return q; // The second element becomes the new head.
    }

    // In-between and Tail Deletion
    ReviewNode *p = NULL;
    p = head;

    while (q != desired_movie){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     * 
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    /*
    Prints out movie_title\n\n
               movie_studio\n\n
               year\n
               BO_total\n
               score\n
               *******************\n
    */

   float total_profit = 0;
   ReviewNode *p = NULL;
   p = head;

   while (p != NULL){
    printf("%s\n", p->review.movie_title);
    printf("%s\n", p->review.movie_studio);
    printf("%d\n", p->review.year);
    printf("%f\n", p->review.BO_total);
    printf("%d\n", p->review.score);
    printf("*******************\n");

    total_profit += p->review.BO_total;
    p = p->next;
   }

   // printf("total_profit = %f", total_profit); // Comment out when done.
   return total_profit; 
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
    ReviewNode *p = NULL;
    p = head;
    float total_profit = 0;

    while (p != NULL){
        if (strcmp(p->review.movie_studio, studio) == 0){
            printf("%s\n", p->review.movie_title);
            printf("%s\n", p->review.movie_studio);
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("*******************\n");

            total_profit += p->review.BO_total;
        }
        p = p->next;
    }

    // printf("total_profit = %f", total_profit); // Comment out when done.
    return total_profit;
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
    ReviewNode *p = NULL;
    p = head;
    float total_profit = 0;

    while (p != NULL){
        if (p->review.score >= min_score){
            printf("%s\n", p->review.movie_title);
            printf("%s\n", p->review.movie_studio);
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("*******************\n");

            total_profit += p->review.BO_total;
        }
        p = p->next;
    }

    // printf("total_profit = %f", total_profit); // Comment out when done.
    return total_profit;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    

    ReviewNode *p = NULL;
    ReviewNode *q = NULL;
    p = head;

    while (p != NULL){
        q = p->next;
        free(p);
        p = q;
    }

    return NULL;
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */ 

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
        
    int num_revs = countReviews(head);
    if (num_revs <= 1) return head;

    ReviewNode *p = NULL;
    MovieReview temp_rev;
    p = head;

    unsigned int counter = 0;

    // This is basically a shitty bubble sort algorithm for LLs...
    // I'm not at all proud of this, but it should work!
    while (counter < num_revs){
        while (p->next != NULL){
            if (strcmp(p->review.movie_title, (p->next)->review.movie_title) > 0){
                temp_rev = p->review;
                p->review = (p->next)->review;
                (p->next)->review = temp_rev;
            }
            p = p->next;
        }
        p = head;
        counter++;
    }

    return head;
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. The new cast member must go to the end of the list.
   * 
   * Duplicate names are allowed - this time! 
   * 
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the 
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   * 
   * If no such movie is found, this function does nothing.
   * 
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */   

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p = findMovieReview(title, studio, year, head);
    if (p == NULL) return; // No movie found! Do nothing...

    CastList *c = (CastList*)calloc(1, sizeof(CastList));
    if (c == NULL) return; // No more space!
    
    strcpy(c->name, name);
    c->salary = salary;
    c->next = NULL;

    // Head Insert - given that the cast list is empty //
    if (p->review.cast == NULL) p->review.cast = c;

    // Tail Insert - o/w //
    else {
        CastList *q = p->review.cast;

        while (q->next != NULL) {
            q = q->next;
        }
        q->next = c;
    }
}

// Helper Function: Returns the number of movies the cast member participated in. {Used in whosTheStar()}
int reviewsPerCast(ReviewNode *head, char *cast_name)
{
    int n = 0;
    ReviewNode *p = head;
    CastList *c = NULL;

    while (p != NULL) {
        c = p->review.cast;
        while (c != NULL) {
            if (strcmp(c->name, cast_name) == 0) {
                n++;
                break; // No duplicates expected.
            }
            c = c->next;
        }
        p = p->next;
    }
    return n;
}

// Helper Function: Calculates the total_salary of a given cast member. {Used in whosTheStar()}
float totalCastSalary(CastList *cast) {
    float total_salary = 0.0;
    CastList *c = cast;

    while (c != NULL) {
        total_salary += c->salary;
        c = c->next;
    }

    return total_salary;
}

void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own. 
   *
   *  The function simply prints out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    if (head == NULL) return;

    ReviewNode *p = head; // Standard movie pointer.
    CastList *c = NULL; // Standard cast pointer.
    ReviewNode *p_copy = NULL; // Needed to traverse the LL twice.
    CastList *c_copy = NULL; // Needed to traverse the castList twice.
    CastList *matching_c = NULL; // Used to look for matching cast members (by name).

    // Initialized w/ junk values to check if any movie/cast was found at the end of the search (as well as for debugging purposes) //
    char *star = NULL;
    float star_earnings = -1.0;

    int num_movies = -1;
    int movies_played = -1;

    float movie_earnings = -1.0;
    float total_salary = -1.0;
    float avg_earnings = -1.0;
    float total_earnings = -1.0;

    while (p != NULL){
        total_salary = 0.0;
        movie_earnings = p->review.BO_total;
        c = p->review.cast; 

        while (c != NULL){
            total_salary += c->salary;
            c = c->next;
        }
        movie_earnings -= total_salary;

        c = p->review.cast; // Reset Cast.

        // Look for other movies where a cast member played //
        while (c != NULL){
            matching_c = p->review.cast; 
            while (matching_c != NULL){

                if (strcmp(c->name, matching_c->name) == 0){
                    num_movies = reviewsPerCast(head, c->name); // Gets the amount of movies the given cast participated in.
                    avg_earnings = 0.0;

                    // If any movies were found containing the cast member, traverse the LL (again) to get their total_earnings //
                    if (num_movies > 0){
                        p_copy = head;
                        total_earnings = 0.0;
                        movies_played = 0;

                        // This is where the second traversal of the LL begins - similar to the two outer while loops //
                        while (p_copy != NULL){
                            c_copy = p_copy->review.cast;
                            while (c_copy != NULL){

                                // If we find a movie the cast played, then we adjust the total_earnings to reflect the new total_earnings //
                                if (strcmp(c_copy->name, c->name) == 0){
                                    total_earnings += (p_copy->review.BO_total - totalCastSalary(p_copy->review.cast));
                                    movies_played++;
                                    break; // After finding the cast member in the given movie, there's no need to look anymore. (Gotta save any last bit of optimization this shitty function has somehow!)
                                }
                                c_copy = c_copy->next;
                            }
                            p_copy = p_copy->next;
                        }

                        // Once we've looked through all the movies where the cast played, we compare to see if it's higher than the current highest earnings //
                        if (movies_played == num_movies){
                            avg_earnings = total_earnings / (float)num_movies;
                            if (avg_earnings > star_earnings){
                                star = c->name;
                                star_earnings = avg_earnings;
                            }
                        }
                    }
                }
                matching_c = matching_c->next;
            }
            c = c->next;
        }
        p = p->next;
    }

    if (star == NULL) return; // Probably not efficient to do it this late but I don't know where to stop it, sooo....

    printf("%s%f\n", star, star_earnings);
}

void printNames(ReviewNode *movie)
{
    // Prints out names of cast members for this movie
    CastList *p;
    
    if (movie==NULL||movie->review.cast==NULL) return;
    
    p=movie->review.cast;
    printf("The cast for this movie are:\n");
    while (p!=NULL)
    {
        printf("Cast Member: %s, Salary: %f\n",p->name,p->salary);
        p=p->next;
    }
}