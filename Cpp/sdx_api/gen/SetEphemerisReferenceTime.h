#pragma once

#include <memory>
#include "command_base.h"
#include <string>
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetEphemerisReferenceTime is deprecated since 21.3. You may use SetEphemerisReferenceTimeForSV.
    /// 
    /// Set the ephemeris reference time for the specified constellation.
    ///
    /// Name   Type     Description
    /// ------ -------- --------------------------------------------------------------
    /// System string   "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId   int      The satellite's SV ID.
    /// Time   datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class SetEphemerisReferenceTime;
    typedef std::shared_ptr<SetEphemerisReferenceTime> SetEphemerisReferenceTimePtr;
    
    
    class SetEphemerisReferenceTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetEphemerisReferenceTime();

      SetEphemerisReferenceTime(const std::string& system, int svId, const Sdx::DateTime& time);
  
      static SetEphemerisReferenceTimePtr create(const std::string& system, int svId, const Sdx::DateTime& time);
      static SetEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** time ****
      Sdx::DateTime time() const;
      void setTime(const Sdx::DateTime& time);
    };
  }
}

