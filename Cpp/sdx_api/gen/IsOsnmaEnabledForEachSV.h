#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if OSNMA is enabled or disabled for each satellite.
    ///
    /// 
    ///

    class IsOsnmaEnabledForEachSV;
    typedef std::shared_ptr<IsOsnmaEnabledForEachSV> IsOsnmaEnabledForEachSVPtr;
    
    
    class IsOsnmaEnabledForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsOsnmaEnabledForEachSV();

      static IsOsnmaEnabledForEachSVPtr create();
      static IsOsnmaEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

