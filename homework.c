// file for use with c tutorial videos
// command line args, structs, datatypes
//SaberKatNX 9-2-2020, free to use/mod/distribute

//Includes here.  These statements with the hashtag '#' are for the preprocessor
//  in addition to #include, there are several other statments you can use
//the second most common on you'll see and use is #define, which you can use to
// make your own constants.  Such as #define HIGH 100, defines a constant HIGH
//as having the value of 100
#include <stdio.h>
#include <stdlib.h>



//prototypes
//A function prototype is just a way of telling the compiler to look out for it
//This acts as an outline of what if any type of data it will return and need
//Think of it as an outline
void process(void);
void defineproblem(void);

//globals
//We don't like to use globals all that often.  They hang out in memory forever.
//Sometimes though, it's easier and less memory intensive
struct math {
            float a;
            float b;
            char operate;
            float solution;
            } problem;

char problemLine[201];
//up until now we've just been throwing int main() down keept going.
//but, main() lets you pass information to your programs!
//so here, we're going to add some extra code into the parens on main()
//and take advantage of command line arguments

int main(int argc, char *argv[])
{

    FILE *in, *out;
    problem.operate = '\0';
//  FILE *in, *out;
    char inPut[65], outPut[65];
    outPut = 'results.txt';
    int counter;
    int buildproblem(FILE *, FILE *);
    //outPut = Out;


    if (argc >= 1){
        switch (argc){
            case 1:  //the program name is always the first argument
                     //since our code doesn't do much on its own
                     //let's tell the user what they're supposed
                     //todo!
                    printf("Usage: homework (expression or filename)\n");
                    break;
            case 2:
                    inPut = *argv[1];
                    if ((in = fopen(inPut, "r")) == NULL){
                        printf("Unable to open %s\n", in);
                        return 1;
                        }
                    if ((out = fopen(outPut, "a")) == NULL){
                        printf("Unable to open %s\n", in);
                        return 2;
                        }
                    buildproblem(in, out);
                    break;
            case 4:
                    //this picks apart the arguments and writes data
                    //to our global struct
                    //atof() is one of several functions in stdlib.h
                    //that lets us take ASCII numbers and makes them
                    //"real" numbers.  Other functions exist to go
                    //the other way.
                    problem.a = atof(argv[1]);
                    problem.b = atof(argv[3]);
                    problem.operate = *argv[2];
                    break;
            default:
                    //if the number of arguments is covered above, do this!
                printf("Usage: homework (expression or file name)\n");
                    break;
            }

       }

     if (problem.operate != '\0')
        process();
        else return 0; //if we didn't do any math, we don't need to go on!

     printf("%.2f\n", problem.solution);

    return 0;
}
//------------------------------------------------------------------------------

void process()
{

    switch (problem.operate){
        case '+':
                problem.solution = problem.a + problem.b;
                break;
        case '-':
                problem.solution = problem.a - problem.b;
                break;
        case 'x':
                problem.solution = problem.a * problem.b;
                break;
        case '/':
                problem.solution = problem.a / problem.b;
                break;
        default:
                printf("Not implemented\n");

        }

    return;

}



//-----------------------------------------------------------------------------
int buildproblem(FILE *in, FILE *out)
{
    int i, x, c;
    i = 0;
    x = 0;


    if (fopen(in, "r") == NULL){
        printf("Unable to open %s\n", in);
        return;
        }
    if (fopen(out, "a") == NULL){
        printf("Unable to open %s\n", in);
        return;
        }

    while (c=getc(in) != EOF){
        while (c = getc(in) != '\n'){
            problemLine[i] = c;
            i++;
            }
            defineproblem();
            fprintf(out, "%.2f %s %.2f = %.2f", problem.a, problem.b, problem.operate, problem.solution);

            i = 0;
    }

    return 0;
}

//------------------------------------------------------------------------------------------------------
void defineproblem()
{
    char valueA[11], valueB[11];
    int i, t;
    i = 0;
    t = 0;
 //---------------------------------------
    while (problemLine[i] != ' '){
        valueA[i] = problemLine[i];
        i++;
        }
    problem.a = atof(valueA);
//-------------------------------------


    problem.operate = problemLine[i];
    i = i+2;


//-------------------------------------------
    while (problemLine[i] != ' '){
        valueB[t] = problemLine[i];
        i++;
        t++;
        }

    problem.b = atof(valueB);

    process();

return;
}






