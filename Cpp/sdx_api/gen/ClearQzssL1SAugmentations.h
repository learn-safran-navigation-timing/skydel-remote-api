#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clears all QZSS L1S augmentations.
    ///
    /// 
    ///

    class ClearQzssL1SAugmentations;
    typedef std::shared_ptr<ClearQzssL1SAugmentations> ClearQzssL1SAugmentationsPtr;
    
    
    class ClearQzssL1SAugmentations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ClearQzssL1SAugmentations();

      static ClearQzssL1SAugmentationsPtr create();
      static ClearQzssL1SAugmentationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

