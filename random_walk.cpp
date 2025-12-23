#include "random_walk.h"

void le_quantidade_agentes(int &quantidade_agentes){
    std::cout << "Digite a quantidade de agentes: \n";
    while(!(std::cin >> quantidade_agentes) || quantidade_agentes <= 0){
        std::cout << "Entrada invalida. Digite um numero inteiro positivo: \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
void Cores_Aleatorias(std::vector<std::vector<int>>& cores, int quantidade_agentes){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 255);
    
    for(int i = 0; i < quantidade_agentes; i++){
        int r = distrib(gen);
        int g = distrib(gen);
        int b = distrib(gen);
        cores.push_back({r, g, b});
    }
}
void Imprime_agentes(std::vector<std::vector<std::pair<float, float>>>& posicoes, std::vector<std::vector<int>>& cores){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-1, 2);

    for(int idx = 0; idx < posicoes.size(); idx++){
        auto& agente = posicoes[idx];
        int d = distrib(gen);
        
        float x = agente.back().first;
        float y = agente.back().second;
        
        switch(d){
            case -1:
                x -= DISTANCE;
                break;
            case 0:
                y -= DISTANCE;
                break;
            case 1:
                x += DISTANCE;
                break;
            case 2:
                y += DISTANCE;
                break;
        }
        agente.push_back({x, y});
    }
    
    for(int idx = 0; idx < posicoes.size(); idx++){
        auto& agente = posicoes[idx];
        for(int i = 0; i < agente.size(); i++){
            al_draw_filled_rectangle(agente[i].first, agente[i].second, agente[i].first + BLOCK_SIZE, agente[i].second + BLOCK_SIZE, al_map_rgb(cores[idx][0], cores[idx][1], cores[idx][2]));
        }
    }
}