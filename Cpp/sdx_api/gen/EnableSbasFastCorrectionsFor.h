#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether specific errors type for this constellation should be compensated in SBAS fast corrections
    ///
    /// Name      Type            Description
    /// --------- --------------- ----------------------------------------------------------------------------------------------------
    /// System    string          "GPS" or "SBAS"
    /// IsEnabled bool            True if corrections are enabled
    /// ErrorType optional string Comma separated error type to enable/disable. Accepted error types are "PSR offset" and "PSR error".
    ///                           Default value is "PSR error". Getter only accepts one error type.
    ///

    class EnableSbasFastCorrectionsFor;
    typedef std::shared_ptr<EnableSbasFastCorrectionsFor> EnableSbasFastCorrectionsForPtr;
    
    
    class EnableSbasFastCorrectionsFor : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSbasFastCorrectionsFor();

      EnableSbasFastCorrectionsFor(const std::string& system, bool isEnabled, const Sdx::optional<std::string>& errorType = {});

      static EnableSbasFastCorrectionsForPtr create(const std::string& system, bool isEnabled, const Sdx::optional<std::string>& errorType = {});
      static EnableSbasFastCorrectionsForPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** isEnabled ****
      bool isEnabled() const;
      void setIsEnabled(bool isEnabled);


      // **** errorType ****
      Sdx::optional<std::string> errorType() const;
      void setErrorType(const Sdx::optional<std::string>& errorType);
    };
    
  }
}

