#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get if map is show/hide in Analysis tab.
    ///
    /// 
    ///

    class IsMapAnalysisEnabled;
    typedef std::shared_ptr<IsMapAnalysisEnabled> IsMapAnalysisEnabledPtr;
    
    
    class IsMapAnalysisEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsMapAnalysisEnabled();

      static IsMapAnalysisEnabledPtr create();
      static IsMapAnalysisEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

