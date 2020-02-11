/*
    Tanzir Ahmed
    Department of Computer Science & Engineering
    Texas A&M University
    Date  : 2/8/20
 */
#include "common.h"
#include "FIFOreqchannel.h"

using namespace std;


int main(int argc, char *argv[]){
    int n = 100;    // default number of requests per "patient"
	int p = 15;		// number of patients
    srand(time_t(NULL));

    FIFORequestChannel chan ("control", FIFORequestChannel::CLIENT_SIDE);

    // sending a non-sense message, you need to change this
    char buf [MAX_MESSAGE];
    char x = 55;
    chan.cwrite (&x, sizeof (x));
    int nbytes = chan.cread (buf, MAX_MESSAGE);

    datamsg d (14, 59.00, 2);
    chan.cwrite (&d, sizeof(datamsg));
    double resp = 0;
    chan.cread(&resp, sizeof (double));
    cout << "Response " <<resp << endl;

    // closing the channel    
    MESSAGE_TYPE m = QUIT_MSG;
    chan.cwrite (&m, sizeof (MESSAGE_TYPE));

   
}
