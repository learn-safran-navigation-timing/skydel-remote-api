#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsPYCodeEnabledForSV.
    ///
    /// Name    Type   Description
    /// ------- ------ -----------------------------------------------
    /// Signal  string Accepted signal keys: "L1P", "L2P"
    /// SvId    int    The satellite's SV ID 1..32 (use 0 for all SVs)
    /// Enabled bool   Enable P(Y)-Code if True
    ///

    class IsPYCodeEnabledForSVResult;
    typedef std::shared_ptr<IsPYCodeEnabledForSVResult> IsPYCodeEnabledForSVResultPtr;
    
    
    class IsPYCodeEnabledForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPYCodeEnabledForSVResult();

      IsPYCodeEnabledForSVResult(const std::string& signal, int svId, bool enabled);

      IsPYCodeEnabledForSVResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled);

      static IsPYCodeEnabledForSVResultPtr create(const std::string& signal, int svId, bool enabled);

      static IsPYCodeEnabledForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled);
      static IsPYCodeEnabledForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(IsPYCodeEnabledForSVResult);
  }
}

