#ifndef STATE_H
#define STATE_H

struct State {
  std::vector<int> block_ids;
  std::vector<bool> orientations;
  std::vector<bool> uncover_rec_num;
  std::vector<bool> ifrotate;
  State() {}
  State(const State* c) {
    block_ids = c->block_ids;
    orientations = c->orientations;
    uncover_rec_num = c->uncover_rec_num;
    ifrotate = c->ifrotate;
  }
  ~State() {}
};

#endif // STATE_H