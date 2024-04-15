#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsOsnmaEnabledForSV.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------------------
    /// SvId    int  The satellite's SV ID (use 0 for all Galileo's satellites).
    /// Enabled bool OSNMA is enabled when value is True.
    ///

    class IsOsnmaEnabledForSVResult;
    typedef std::shared_ptr<IsOsnmaEnabledForSVResult> IsOsnmaEnabledForSVResultPtr;
    
    
    class IsOsnmaEnabledForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsOsnmaEnabledForSVResult();

      IsOsnmaEnabledForSVResult(int svId, bool enabled);

      IsOsnmaEnabledForSVResult(CommandBasePtr relatedCommand, int svId, bool enabled);

      static IsOsnmaEnabledForSVResultPtr create(int svId, bool enabled);

      static IsOsnmaEnabledForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool enabled);
      static IsOsnmaEnabledForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsOsnmaEnabledForSVResult);
  }
}

