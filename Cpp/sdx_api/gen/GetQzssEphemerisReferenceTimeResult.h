#pragma once

#include <memory>
#include "command_result.h"
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssEphemerisReferenceTime
    ///
    /// Name Type     Description
    /// ---- -------- --------------------------------------------------------------
    /// SvId int      Satellite SV ID 1..10
    /// Time datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class GetQzssEphemerisReferenceTimeResult;
    typedef std::shared_ptr<GetQzssEphemerisReferenceTimeResult> GetQzssEphemerisReferenceTimeResultPtr;
    
    
    class GetQzssEphemerisReferenceTimeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphemerisReferenceTimeResult();

      GetQzssEphemerisReferenceTimeResult(CommandBasePtr relatedCommand, int svId, const Sdx::DateTime& time);
  
      static GetQzssEphemerisReferenceTimeResultPtr create(CommandBasePtr relatedCommand, int svId, const Sdx::DateTime& time);
      static GetQzssEphemerisReferenceTimeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** time ****
      Sdx::DateTime time() const;
      void setTime(const Sdx::DateTime& time);
    };
  }
}

