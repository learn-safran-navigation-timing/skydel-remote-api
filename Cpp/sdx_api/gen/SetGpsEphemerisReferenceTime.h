#pragma once

#include <memory>
#include "command_base.h"
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsEphemerisReferenceTime is deprecated since 21.3. You may use EphemerisReferenceTimeForSV.
    /// 
    /// Set the GPS ephemeris reference time
    ///
    /// Name Type     Description
    /// ---- -------- --------------------------------------------------------------
    /// Prn  int      Satellite PRN number 1..32
    /// Time datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class SetGpsEphemerisReferenceTime;
    typedef std::shared_ptr<SetGpsEphemerisReferenceTime> SetGpsEphemerisReferenceTimePtr;
    
    
    class SetGpsEphemerisReferenceTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsEphemerisReferenceTime();

      SetGpsEphemerisReferenceTime(int prn, const Sdx::DateTime& time);
  
      static SetGpsEphemerisReferenceTimePtr create(int prn, const Sdx::DateTime& time);
      static SetGpsEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** time ****
      Sdx::DateTime time() const;
      void setTime(const Sdx::DateTime& time);
    };
  }
}

