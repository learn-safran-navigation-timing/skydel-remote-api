#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the simulation GPS start date and time and leap second to convert into UTC time
    ///
    /// 
    ///

    class GetGpsStartTime;
    typedef std::shared_ptr<GetGpsStartTime> GetGpsStartTimePtr;
    
    
    class GetGpsStartTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsStartTime();

      static GetGpsStartTimePtr create();
      static GetGpsStartTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

