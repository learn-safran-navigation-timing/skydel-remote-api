#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasEphemerisReferenceTimeForSV.
    ///
    /// Name Type     Description
    /// ---- -------- ---------------------------------------------------------------
    /// SvId int      The satellite's SV ID.
    /// Time datetime GPS date and time (it is the GPS time expressed in UTC format).
    ///

    class GetSbasEphemerisReferenceTimeForSVResult;
    typedef std::shared_ptr<GetSbasEphemerisReferenceTimeForSVResult> GetSbasEphemerisReferenceTimeForSVResultPtr;
    
    
    class GetSbasEphemerisReferenceTimeForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasEphemerisReferenceTimeForSVResult();

      GetSbasEphemerisReferenceTimeForSVResult(int svId, const Sdx::DateTime& time);

      GetSbasEphemerisReferenceTimeForSVResult(CommandBasePtr relatedCommand, int svId, const Sdx::DateTime& time);

      static GetSbasEphemerisReferenceTimeForSVResultPtr create(int svId, const Sdx::DateTime& time);

      static GetSbasEphemerisReferenceTimeForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const Sdx::DateTime& time);
      static GetSbasEphemerisReferenceTimeForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** time ****
      Sdx::DateTime time() const;
      void setTime(const Sdx::DateTime& time);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasEphemerisReferenceTimeForSVResult);
  }
}

