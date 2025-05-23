#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes a specific interference signal.
    ///
    /// Name Type   Description
    /// ---- ------ -------------------------------------------------------
    /// Id   string Unique identifier of the interference signal to remove.
    ///

    class RemoveInterference;
    typedef std::shared_ptr<RemoveInterference> RemoveInterferencePtr;
    
    
    class RemoveInterference : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveInterference();

      RemoveInterference(const std::string& id);

      static RemoveInterferencePtr create(const std::string& id);
      static RemoveInterferencePtr dynamicCast(CommandBasePtr ptr);
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

