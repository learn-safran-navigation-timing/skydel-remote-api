#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes a multipath signal.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------------------
    /// Id   string Unique identifier of the multipath signal to remove.
    ///

    class RemoveMultipath;
    typedef std::shared_ptr<RemoveMultipath> RemoveMultipathPtr;
    
    
    class RemoveMultipath : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveMultipath();

      RemoveMultipath(const std::string& id);

      static RemoveMultipathPtr create(const std::string& id);
      static RemoveMultipathPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

