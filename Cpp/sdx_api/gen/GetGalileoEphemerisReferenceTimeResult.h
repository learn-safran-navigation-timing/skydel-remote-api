#pragma once

#include <memory>
#include "command_result.h"
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoEphemerisReferenceTime.
    ///
    /// Name Type     Description
    /// ---- -------- --------------------------------------------------------------
    /// Prn  int      Satellite PRN number 1..36
    /// Time datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class GetGalileoEphemerisReferenceTimeResult;
    typedef std::shared_ptr<GetGalileoEphemerisReferenceTimeResult> GetGalileoEphemerisReferenceTimeResultPtr;
    
    
    class GetGalileoEphemerisReferenceTimeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoEphemerisReferenceTimeResult();

      GetGalileoEphemerisReferenceTimeResult(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time);
  
      static GetGalileoEphemerisReferenceTimeResultPtr create(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time);
      static GetGalileoEphemerisReferenceTimeResultPtr dynamicCast(CommandBasePtr ptr);
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

