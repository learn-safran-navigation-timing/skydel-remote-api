#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes the custom signal with the given ID
    ///
    /// Name Type   Description
    /// ---- ------ ----------------
    /// Id   string Custom signal ID
    ///

    class RemoveCustomSignal;
    typedef std::shared_ptr<RemoveCustomSignal> RemoveCustomSignalPtr;
    
    
    class RemoveCustomSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveCustomSignal();

      RemoveCustomSignal(const std::string& id);

      static RemoveCustomSignalPtr create(const std::string& id);
      static RemoveCustomSignalPtr dynamicCast(CommandBasePtr ptr);
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

