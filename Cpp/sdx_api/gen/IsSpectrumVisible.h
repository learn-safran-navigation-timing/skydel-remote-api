#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get if spectrums are show/hide.
    ///
    /// 
    ///

    class IsSpectrumVisible;
    typedef std::shared_ptr<IsSpectrumVisible> IsSpectrumVisiblePtr;
    
    
    class IsSpectrumVisible : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSpectrumVisible();

      static IsSpectrumVisiblePtr create();
      static IsSpectrumVisiblePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

