#include <iostream>
#include <algorithm>
#include <fstream>
//#include <random>
#include "Player.h"

int main() {
    using size = std::size_t;
    std::ifstream inFile("input.csv");
    std::ofstream outFile("output.csv");

    size player_cnt,team_cnt,team_size; // number of players, number of teams, number of players in team
    Player *get_player;
    Player **player;
    double *sum;

    if(!inFile.is_open()) {
        std::cout << "CONSOLE INPUT MODE\nEnter number of players and size of each team separated with ',':\n";
        std::string tmp_string;
        std::getline(std::cin, tmp_string);
        for (size i = 0; i < tmp_string.size(); i++) {
            if (tmp_string[i] == ',') {
                player_cnt = std::stoul(tmp_string.substr(0, i));
                team_size = std::stoul(tmp_string.substr(i + 1));
                team_cnt = player_cnt / team_size;
                break;
            }
        }

        get_player = new Player[player_cnt];
        for (size i = 0; i < player_cnt; i++) {
            // double x=(10000/6.0*j)+((double)std::rand()/RAND_MAX)*(10000/6.0);
            std::string name;
            double mmr;
            std::getline(std::cin, name);
            for (size k = 0; k < name.size(); k++) {
                if (name[k] == ',') {
                    auto s = name.substr(0, k);
                    mmr = std::stod(name.substr(k + 1));
                    name = s;
                    break;
                }
            }
            get_player[i] = Player(name, mmr);
        }
    }
    else{
        std::string tmp_string;
        std::getline(inFile, tmp_string);
        for (size i = 0; i < tmp_string.size(); i++) {
            if (tmp_string[i] == ',') {
                player_cnt = std::stoul(tmp_string.substr(0, i));
                team_size = std::stoul(tmp_string.substr(i + 1));
                team_cnt = player_cnt / team_size;
                break;
            }
        }

        get_player = new Player[player_cnt];
        for (size i = 0; i < player_cnt; i++) {
            std::string name;
            double mmr;
            std::getline(inFile, name);
            for (size k = 0; k < name.size(); k++) {
                if (name[k] == ',') {
                    auto s = name.substr(0, k);
                    mmr = std::stod(name.substr(k + 1));
                    name = s;
                    break;
                }
            }
            get_player[i] = Player(name, mmr);
        }
    }

    std::sort(get_player,get_player+player_cnt);

    sum=new double[team_cnt]();
    player=new Player*[team_cnt];

    for(size i=0;i<team_cnt;i++){
        player[i]=new Player[team_size];
        for(size j=0;j<team_size;j++){
            player[i][j]=get_player[i+j*team_cnt];
            sum[i]+=player[i][j].get_mmr();
        }
    }
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=0;i<team_cnt-1;i++){
            for(int j=i+1;j<team_cnt;j++){
                for (int k=0;k<team_size;k++) {
                    if((player[i][k]>player[j][k]&&sum[i]-player[i][k]>sum[j]-player[j][k])||(player[i][k]<player[j][k]&&sum[i]-player[i][k]<sum[j]-player[j][k])){
                        double x=player[i][k]-player[j][k];
                        sum[i]-=x;
                        sum[j]+=x;
                        std::swap(player[i][k],player[j][k]);
                        flag=true;
                    }
                    else continue;
                }
            }
        }
    }
    for (int i=0;i<team_cnt;i++) {
        for (int j=0;j<team_size;j++) {
            std::cout<< player[i][j] << '\t';
            outFile<<player[i][j]<<',';
        }
        std::cout<<" || "<<sum[i];
        outFile<<','<<sum[i]<<'\n';
        std::cout<<std::endl;
    }


    delete[] sum;
    delete[] get_player;
    for(int i=0;i<team_cnt;i++){
        delete[] player[i];
    }
    delete[] player;
}