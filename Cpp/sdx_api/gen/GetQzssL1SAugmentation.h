#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Add an augmentation to the L1S navigation messages.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------------------
    /// Id   string Unique identifier of the augmentation.
    ///

    class GetQzssL1SAugmentation;
    typedef std::shared_ptr<GetQzssL1SAugmentation> GetQzssL1SAugmentationPtr;
    
    
    class GetQzssL1SAugmentation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetQzssL1SAugmentation();

      GetQzssL1SAugmentation(const std::string& id);

      static GetQzssL1SAugmentationPtr create(const std::string& id);
      static GetQzssL1SAugmentationPtr dynamicCast(CommandBasePtr ptr);
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

