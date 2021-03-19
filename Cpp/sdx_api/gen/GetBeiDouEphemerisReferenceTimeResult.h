#pragma once

#include <memory>
#include "command_result.h"
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouEphemerisReferenceTime
    ///
    /// Name Type     Description
    /// ---- -------- --------------------------------------------------------------
    /// Prn  int      Satellite PRN number 1..30
    /// Time datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class GetBeiDouEphemerisReferenceTimeResult;
    typedef std::shared_ptr<GetBeiDouEphemerisReferenceTimeResult> GetBeiDouEphemerisReferenceTimeResultPtr;
    
    
    class GetBeiDouEphemerisReferenceTimeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphemerisReferenceTimeResult();

      GetBeiDouEphemerisReferenceTimeResult(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time);
  
      static GetBeiDouEphemerisReferenceTimeResultPtr create(CommandBasePtr relatedCommand, int prn, const Sdx::DateTime& time);
      static GetBeiDouEphemerisReferenceTimeResultPtr dynamicCast(CommandBasePtr ptr);
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

