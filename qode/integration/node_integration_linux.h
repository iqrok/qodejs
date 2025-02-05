// Copyright 2014 GitHub, Inc.
// Copyright 2017 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the MIT license.

#ifndef SRC_NODE_INTEGRATION_LINUX_H_
#define SRC_NODE_INTEGRATION_LINUX_H_

#include "qode/integration/node_integration.h"

namespace qode {

class NodeIntegrationLinux : public NodeIntegration {
 public:
  NodeIntegrationLinux();
  ~NodeIntegrationLinux() override;

 private:
  void PollEvents() override;
  void PostTask(const std::function<void()>& task) override;

  // Called when uv's watcher queue changes.
  static void OnWatcherQueueChanged(uv_loop_t* loop);

  // Epoll to poll for uv's backend fd.
  int epoll_;

};

}  // namespace qode

#endif  // SRC_NODE_INTEGRATION_LINUX_H_