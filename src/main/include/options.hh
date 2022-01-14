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

#ifndef EDB_OPTIONS_HH
#define EDB_OPTIONS_HH

#include "common.hh"

namespace edb {
class EdbOptions {
public:
  EdbOptions();
  ~EdbOptions();

public:
  int Parse(int argc, char **argv);

  // region getter

  int GetPort();
  int GetPoolSize();
  const char *GetSrvName();
  const char *GetBaseDir();
  const char *GetDataDir();

  // endregion getter

private:
  const char *base_dir_{};
  const char *data_dir_{};
  const char *name_{};
  int port_{};
  int pool_size_{};
};

} // namespace edb
#endif // EDB_OPTIONS_HH
