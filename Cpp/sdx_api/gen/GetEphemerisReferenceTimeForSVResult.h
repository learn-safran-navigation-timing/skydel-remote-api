#pragma once

#include <memory>
#include "command_result.h"
#include "date_time.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetEphemerisReferenceTimeForSV
    ///
    /// Name   Type     Description
    /// ------ -------- --------------------------------------------------------------
    /// System string   "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId   int      The satellite's SV ID.
    /// Time   datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class GetEphemerisReferenceTimeForSVResult;
    typedef std::shared_ptr<GetEphemerisReferenceTimeForSVResult> GetEphemerisReferenceTimeForSVResultPtr;
    typedef GetEphemerisReferenceTimeForSVResult GetEphemerisReferenceTimeResult;
    typedef std::shared_ptr<GetEphemerisReferenceTimeResult> GetEphemerisReferenceTimeResultPtr;
    
    class GetEphemerisReferenceTimeForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetEphemerisReferenceTimeForSVResult();

      GetEphemerisReferenceTimeForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::DateTime& time);
  
      static GetEphemerisReferenceTimeForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const Sdx::DateTime& time);
      static GetEphemerisReferenceTimeForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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

