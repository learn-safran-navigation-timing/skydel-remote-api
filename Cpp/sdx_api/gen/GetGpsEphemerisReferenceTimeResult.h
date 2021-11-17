#pragma once

#include <memory>
#include "command_result.h"
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsEphemerisReferenceTime.
    ///
    /// Name Type     Description
    /// ---- -------- --------------------------------------------------------------
    /// Prn  int      Satellite PRN number 1..32
    /// Time datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class GetGpsEphemerisReferenceTimeResult;
    typedef std::shared_ptr<GetGpsEphemerisReferenceTimeResult> GetGpsEphemerisReferenceTimeResultPtr;
    
    
    class GetGpsEphemerisReferenceTimeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphemerisReferenceTimeResult();

      GetGpsEphemerisReferenceTimeResult(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time);
  
      static GetGpsEphemerisReferenceTimeResultPtr create(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time);
      static GetGpsEphemerisReferenceTimeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** time ****
      Sdx::DateTime time() const;
      void setTime(const Sdx::DateTime& time);
    };
  }
}

