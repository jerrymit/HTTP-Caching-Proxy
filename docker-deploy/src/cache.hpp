#ifndef CACHE_HPP
#define CACHE_HPP

#include <netdb.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "request.hpp"
#include "response.hpp"

class Cache {
  int capacity;
  std::ofstream& proxy_log;
  std::unordered_map<std::string, Response> cachePipe;
  std::queue<std::string> cacheQueue;

 public:
  Cache(int capacity, std::ofstream & proxy_log) :
      capacity(capacity), proxy_log(proxy_log){};
  void addToCache(Request req, Response res);
  bool checkValidate(Request req, Response res, int request_id);
  Response * getCacheResonse(Request req, int fd);
  bool isInCache(Request req);
};

#endif
