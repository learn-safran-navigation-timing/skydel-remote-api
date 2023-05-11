#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Reset the PRNs of all satellites in specified system, for all signals.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class ResetToDefaultPrn;
    typedef std::shared_ptr<ResetToDefaultPrn> ResetToDefaultPrnPtr;
    
    
    class ResetToDefaultPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ResetToDefaultPrn();

      ResetToDefaultPrn(const std::string& system);

      static ResetToDefaultPrnPtr create(const std::string& system);
      static ResetToDefaultPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

