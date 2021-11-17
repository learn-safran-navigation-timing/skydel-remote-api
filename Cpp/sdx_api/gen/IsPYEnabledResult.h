#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsPYEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------
    /// Prn     int    Satellite PRN number
    /// Signal  string Signal key - see command description for possible values
    /// Enabled bool   Enable P(Y)-Code if True.
    ///

    class IsPYEnabledResult;
    typedef std::shared_ptr<IsPYEnabledResult> IsPYEnabledResultPtr;
    
    
    class IsPYEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPYEnabledResult();

      IsPYEnabledResult(CommandBasePtr relatedCommand, int prn, const std::string& signal, bool enabled);
  
      static IsPYEnabledResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& signal, bool enabled);
      static IsPYEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

