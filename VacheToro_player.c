/* This is the code for the Player of the guessing game Vache Toro
By Firas Hares. 2023
*/
#include <iostream>
#include <vector>



using namespace std;

vector<vector<int> > propos;    //contains all the suggestions
vector<vector<int> > answers;   //contains all the answers of the opponent



void answer(int a, int b, int c, int d, int t, int v){
    /*
        input:  a,b,c,d: the suggested code
                t,v: the answer given by the opponent
        output: void
        description:
                Add a new answer to the Database
    
    */
    vector<int> tmp;
    tmp.push_back(a);
    tmp.push_back(b);
    tmp.push_back(c);
    tmp.push_back(d);
    propos.push_back(tmp);
    
    vector<int> atmp;
    atmp.push_back(t);
    atmp.push_back(v);
    answers.push_back(atmp);
    
}

void calc_t_v(int a, int b, int c, int d, int&t, int &v, int oa, int ob, int oc, int od){
    
    /*
        input:  a,b,c,d: the code from the answers Database
                t,v: the calculated T V
                oa, ob, oc, od: the code supposed to be true
        output: void
        description:
                Calculates the T and V difference between a code and a code from the answers Database
    
    */
    t = 0;
    v = 0;
    if (a==oa) t++;
    if (b==ob) t++;
    if (c==oc) t++;
    if (d==od) t++;
    
    if (a==ob || a==oc || a==od ) v++;
    if (b==oa || b==oc || b==od ) v++;
    if (c==oa || c==ob || c==od ) v++;
    if (d==oa || d==ob || d==oc ) v++;
    
    
}

bool check_on_prev_rules(int a, int b, int c, int d){
    
    /*
        input:  a,b,c,d: the suggested code
        output: true: if code conforms to the previous rules in the Answers Database
                false: if the code is not consistent with the previous rules in the Answers Database
        description:
                Checks if a code is possible when considering the previous answers in the Database
    
    */
    for (int i = 0; i < answers.size(); i ++){
        int t =0;
        int v =0;
        calc_t_v(propos[i][0],propos[i][1],propos[i][2],propos[i][3],t,v,a,b,c,d);
        if (t!=answers[i][0] || v!=answers[i][1])
            return false;
        
    }
    return true;
    
}


void run_possilities_finder(){
    //vector containing the possible remaining codes
    vector<vector<int> > possibilities;
    
    for (int a= 1; a<10; a++){
        for (int b=0; b < 10; b++){
            for (int c=0; c < 10; c++){
                for (int d=0; d < 10; d++){
                    
                    if (a == b)
                        continue;
                    if (a == c)
                        continue;
                    if (a == d)
                        continue;
                    if (b == c)
                        continue;
                        
                    if (b == d)
                        continue;
                    if (c == d)
                        continue;
                    if (!check_on_prev_rules(a, b, c, d))
                        continue;
                    vector<int> tmp;
                    tmp.push_back(a);
                    tmp.push_back(b);
                    tmp.push_back(c);
                    tmp.push_back(d);
                    possibilities.push_back(tmp);
                }
            }
        }
    }
    if (possibilities.size() > 1){
        cout<<"Remaining Possibilities: "<<possibilities.size()<<endl;
        int suggest_position = int(possibilities.size()/2);
        cout<<"Suggestion Position: "<<suggest_position<<endl;
        cout<<"Suggestion: "<<possibilities[suggest_position][0]<<possibilities[suggest_position][1]<<possibilities[suggest_position][2]<<possibilities[suggest_position][3]<<endl;
    }else{
        cout<<"FOUD IT !!!!"<<endl;
        cout<<"The Secret Number is: "<<possibilities[0][0]<<possibilities[0][1]<<possibilities[0][2]<<possibilities[0][3]<<endl;
    }
    
}

int main() {
    
    /*write the suggestion along with the Answers from the opponet here*/
    
    answer(2, 1, 4, 7, 0, 2);
    answer(4, 9, 7, 8, 0, 2);
    answer(7, 3, 9, 2, 2, 1);
    answer(7,2,9,0, 3, 0);
    answer(7,2,9,6, 3,0);
    
    run_possilities_finder();
    
    
    
    
    return 0;
}