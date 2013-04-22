// Copyright (c) 2013 GitHub, Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_ATOM_BROWSER_MAIN_PARTS_
#define ATOM_BROWSER_ATOM_BROWSER_MAIN_PARTS_

#include "brightray/browser/browser_main_parts.h"

namespace atom {

class AtomBrowserBindings;
class NodeBindings;

class AtomBrowserMainParts : public brightray::BrowserMainParts {
 public:
  AtomBrowserMainParts();
  virtual ~AtomBrowserMainParts();

  static AtomBrowserMainParts* Get();

  AtomBrowserBindings* atom_bindings() { return atom_bindings_.get(); }

 protected:
  // Implementations of brightray::BrowserMainParts.
  virtual brightray::BrowserContext* CreateBrowserContext() OVERRIDE;

  // Implementations of content::BrowserMainParts.
  virtual void PostEarlyInitialization() OVERRIDE;
  virtual void PreMainMessageLoopStart() OVERRIDE;
  virtual void PreMainMessageLoopRun() OVERRIDE;

 private:
  scoped_ptr<AtomBrowserBindings> atom_bindings_;
  scoped_ptr<NodeBindings> node_bindings_;

  static AtomBrowserMainParts* self_;

  DISALLOW_COPY_AND_ASSIGN(AtomBrowserMainParts);
};

}  // namespace atom

#endif  // ATOM_BROWSER_ATOM_BROWSER_MAIN_PARTS_
