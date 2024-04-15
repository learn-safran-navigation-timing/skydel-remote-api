#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Indicates if noise level adjustment for Advanced Jammers on Dektec is enabled.
    ///
    /// 
    ///

    class IsDektecAdjustedNoiseEnabled;
    typedef std::shared_ptr<IsDektecAdjustedNoiseEnabled> IsDektecAdjustedNoiseEnabledPtr;
    
    
    class IsDektecAdjustedNoiseEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsDektecAdjustedNoiseEnabled();

      static IsDektecAdjustedNoiseEnabledPtr create();
      static IsDektecAdjustedNoiseEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

