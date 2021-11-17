#pragma once

#include <memory>
#include "command_base.h"
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetQzssEphemerisReferenceTime is deprecated since 20.9. You may use SetEphemerisReferenceTimeForSV.
    /// 
    /// Set the QZSS ephemeris reference time
    ///
    /// Name Type     Description
    /// ---- -------- --------------------------------------------------------------
    /// SvId int      Satellite SV ID 1..10
    /// Time datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class SetQzssEphemerisReferenceTime;
    typedef std::shared_ptr<SetQzssEphemerisReferenceTime> SetQzssEphemerisReferenceTimePtr;
    
    
    class SetQzssEphemerisReferenceTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssEphemerisReferenceTime();

      SetQzssEphemerisReferenceTime(int svId, const Sdx::DateTime& time);
  
      static SetQzssEphemerisReferenceTimePtr create(int svId, const Sdx::DateTime& time);
      static SetQzssEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** time ****
      Sdx::DateTime time() const;
      void setTime(const Sdx::DateTime& time);
    };
  }
}

