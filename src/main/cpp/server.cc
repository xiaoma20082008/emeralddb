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
// Created by chunxiao ma on 2022/1/13.
//
#include "server.hh"
#include <chrono>
#include <csignal>
#include <spdlog/spdlog.h>
#include <thread>
namespace edb {
using namespace std;
using namespace std::chrono_literals;

static void OnSignal(int code) {
  spdlog::info("code=%d", code);
  EdbServer::GetInstance()->Close();
}

EdbServer::EdbServer() noexcept {}
EdbServer::~EdbServer() noexcept { Close(); }
EdbServer *EdbServer::GetInstance() noexcept {
  static EdbServer server{};
  return &server;
}

int EdbServer::Init(int argc, char **argv) noexcept {
  int ret = options_.Parse(argc, argv);
  if (ret == EDB_OK) {
    this->initialized_ = true;
  }
  return ret;
}

int EdbServer::Start() noexcept {
  this->running_ = true;

  std::signal(SIGINT, OnSignal);
  std::signal(SIGQUIT, OnSignal);
  std::signal(SIGKILL, OnSignal);
  std::signal(SIGTERM, OnSignal);
  return EDB_OK;
}

int EdbServer::Await() noexcept {
  while (this->running_) {
    std::this_thread::sleep_for(1000ms);
  }
  return EDB_OK;
}

void EdbServer::Close() noexcept { this->running_ = false; }

} // namespace edb