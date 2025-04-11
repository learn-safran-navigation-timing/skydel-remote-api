#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Indicates if the Earth mask is enabled.
    ///
    /// 
    ///

    class IsEarthMaskEnabled;
    typedef std::shared_ptr<IsEarthMaskEnabled> IsEarthMaskEnabledPtr;
    
    
    class IsEarthMaskEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsEarthMaskEnabled();

      static IsEarthMaskEnabledPtr create();
      static IsEarthMaskEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

