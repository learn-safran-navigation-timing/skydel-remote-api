#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all QZSS L1S augmentation's IDs.
    ///
    /// 
    ///

    class GetQzssL1SAugmentations;
    typedef std::shared_ptr<GetQzssL1SAugmentations> GetQzssL1SAugmentationsPtr;
    
    
    class GetQzssL1SAugmentations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1SAugmentations();

      static GetQzssL1SAugmentationsPtr create();
      static GetQzssL1SAugmentationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

