#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes a QZSS L1S augmentation.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------------
    /// Id   string Unique identifier (see SetQzssL1SAugmentation)
    ///

    class RemoveQzssL1SAugmentation;
    typedef std::shared_ptr<RemoveQzssL1SAugmentation> RemoveQzssL1SAugmentationPtr;
    
    
    class RemoveQzssL1SAugmentation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveQzssL1SAugmentation();

      RemoveQzssL1SAugmentation(const std::string& id);

      static RemoveQzssL1SAugmentationPtr create(const std::string& id);
      static RemoveQzssL1SAugmentationPtr dynamicCast(CommandBasePtr ptr);
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

