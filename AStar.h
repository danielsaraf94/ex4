//
// Created by daniels on 15/01/2020.
//

#ifndef EX4_5__ASTAR_H_
#define EX4_5__ASTAR_H_
#include "Searcher.h"
#include "unordered_map"
#include "queue"
#include <cmath>
#include <set>
#include "Point.h"
template<typename T>
class AStar : public Searcher<T, vector<State<T>>> {
  int num_of_node_evaluated = 0;
 public:
  Searcher<T, vector<State<T>>> *getClone() {
    return new AStar<T>();
  };
  int getNumberOfNodeEvaluated() { return num_of_node_evaluated; }

  Solution<vector<State<T>>> search(Searchable<T> &searchable) {
    State<T> *current;
    list<State<T> *> list;
    set<State<T>> open_set;
    open_set.insert(*(searchable.getInitialState()));
    unordered_map<State<T>, State<T>> came_from;
    unordered_map<State<T>, int> g_score;
    g_score[*searchable.getInitialState()] = 0;
    unordered_map<State<T>, int> f_score;
    f_score[*searchable.getInitialState()] = getH(*searchable.getInitialState(), searchable);

    while (!open_set.empty()) {
      num_of_node_evaluated++;
      current = findLowestFscore(open_set, f_score);
      if (searchable.isGoalState(current))
        return reconstruct_path(came_from, current);
      open_set.erase(*current);
      list = searchable.getAllPossibleStates(current);
      for (State<T> *neighbor : list) {
        double tentative_gScore = g_score[*current] + (neighbor->getCost() - current->getCost());
        if ((tentative_gScore < g_score[*neighbor]) || g_score[*neighbor] == 0) {
          came_from[*neighbor] = *current;
          cout<<neighbor->getState()<<endl;
          g_score[*neighbor] = tentative_gScore;
          f_score[*neighbor] = g_score[*neighbor] + getH(*neighbor, searchable);
          if (open_set.find(*neighbor) == open_set.end())
            open_set.insert(*neighbor);
        }
      }
    }
    throw "can not reach goal";
  }

  Solution<vector<State<T>>> reconstruct_path(unordered_map<State<T>, State<T>> came_from, State<T> *current) {
    //vector<State<T>> total_path;
    //  while (came_from.find(current) != came_from.end())
    //  total_path.prepend(current);
    //current = came_from[current];
    //Solution<vector<State<T>>> solution;
    //solution.SetSolutionDescribe(total_path);
    //return solution;
  }

  double getH(State<Point> node, Searchable<Point> &searchable) {
    State<Point> *goal = searchable.getGoalState();
    int dx = abs(node.getState().getX() - goal->getState().getX());
    int dy = abs(node.getState().getY() - goal->getState().getY());
    return (dx + dy);
  }

  State<T> *findLowestFscore(set<State<T>> open_set, unordered_map<State<T>, int> f_score) {
    State<T> *lowest = new State<T>();
    int min_fscore=999999999;
    for (State<T> s : open_set){
      if(f_score[s]<min_fscore){
        min_fscore=f_score[s];
        lowest = &s;
      }
    }

    lowest = new State<T>(lowest->getCost(), lowest->getState(), lowest->getCameFrom());
    return lowest;
  }
};

#endif //EX4_5__ASTAR_H_
//10 00 02 11