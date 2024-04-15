#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassAlmanacUnhealthyFlagForSV.
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------------------------------------
    /// SvId   int  The satellite's SV ID 1..24
    /// Health bool Status, false = Non-operability, true = Operability (Good)
    ///

    class GetGlonassAlmanacUnhealthyFlagForSVResult;
    typedef std::shared_ptr<GetGlonassAlmanacUnhealthyFlagForSVResult> GetGlonassAlmanacUnhealthyFlagForSVResultPtr;
    
    
    class GetGlonassAlmanacUnhealthyFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGlonassAlmanacUnhealthyFlagForSVResult();

      GetGlonassAlmanacUnhealthyFlagForSVResult(int svId, bool health);

      GetGlonassAlmanacUnhealthyFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool health);

      static GetGlonassAlmanacUnhealthyFlagForSVResultPtr create(int svId, bool health);

      static GetGlonassAlmanacUnhealthyFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetGlonassAlmanacUnhealthyFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGlonassAlmanacUnhealthyFlagForSVResult);
  }
}

