#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassEphemerisHealthFlagForSV.
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------
    /// SvId   int  The satellite's SV ID 1..24
    /// Health bool Status, false = OK, true = Malfunction
    ///

    class GetGlonassEphemerisHealthFlagForSVResult;
    typedef std::shared_ptr<GetGlonassEphemerisHealthFlagForSVResult> GetGlonassEphemerisHealthFlagForSVResultPtr;
    
    
    class GetGlonassEphemerisHealthFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassEphemerisHealthFlagForSVResult();

      GetGlonassEphemerisHealthFlagForSVResult(int svId, bool health);

      GetGlonassEphemerisHealthFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool health);

      static GetGlonassEphemerisHealthFlagForSVResultPtr create(int svId, bool health);

      static GetGlonassEphemerisHealthFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetGlonassEphemerisHealthFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetGlonassEphemerisHealthFlagForSVResult);
  }
}

