#pragma once

#include <memory>
#include "command_base.h"

#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the ephemeris reference time for a SBAS satellite.
    ///
    /// Name Type     Description
    /// ---- -------- ---------------------------------------------------------------
    /// SvId int      The satellite's SV ID.
    /// Time datetime GPS date and time (it is the GPS time expressed in UTC format).
    ///

    class SetSbasEphemerisReferenceTimeForSV;
    typedef std::shared_ptr<SetSbasEphemerisReferenceTimeForSV> SetSbasEphemerisReferenceTimeForSVPtr;
    
    
    class SetSbasEphemerisReferenceTimeForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSbasEphemerisReferenceTimeForSV();

      SetSbasEphemerisReferenceTimeForSV(int svId, const Sdx::DateTime& time);

      static SetSbasEphemerisReferenceTimeForSVPtr create(int svId, const Sdx::DateTime& time);
      static SetSbasEphemerisReferenceTimeForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

