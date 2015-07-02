#ifndef CONTENT_H
#define CONTENT_H

struct Content {
  std::vector<int> block_ids;
  std::vector<bool> orientations;
  std::vector<bool> uncover_rec_num;
  std::vector<bool> ifrotate;
  Content() {}
  Content(const Content* c) {
    block_ids = c->block_ids;
    orientations = c->orientations;
    uncover_rec_num = c->uncover_rec_num;
    ifrotate = c->ifrotate;
  }
  ~Content() {}
};

#endif