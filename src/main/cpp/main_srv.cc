// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
// Created by chunxiao ma on 2022/1/12.
//
#include "server.hh"
#include <spdlog/spdlog.h>
using namespace edb;

int main(int argc, char **argv) {
  do {
    int ret = EdbServer::GetInstance()->Init(argc, argv);
    spdlog::info("initialized...");
    if (ret != EDB_OK) {
      break;
    }
    ret = EdbServer::GetInstance()->Start();
    spdlog::info("started...");
    if (ret != EDB_OK) {
      EdbServer::GetInstance()->Close();
      break;
    }
    EdbServer::GetInstance()->Await();
  } while (false);
  return 0;
}