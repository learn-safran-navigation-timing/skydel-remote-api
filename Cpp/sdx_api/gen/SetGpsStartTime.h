#pragma once

#include <memory>
#include "command_base.h"

#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the simulation start date and time
    ///
    /// Name  Type     Description
    /// ----- -------- --------------------------------------------------------------
    /// Start datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class SetGpsStartTime;
    typedef std::shared_ptr<SetGpsStartTime> SetGpsStartTimePtr;
    
    
    class SetGpsStartTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGpsStartTime();

      SetGpsStartTime(const Sdx::DateTime& start);

      static SetGpsStartTimePtr create(const Sdx::DateTime& start);
      static SetGpsStartTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** start ****
      Sdx::DateTime start() const;
      void setStart(const Sdx::DateTime& start);
    };
    
  }
}

