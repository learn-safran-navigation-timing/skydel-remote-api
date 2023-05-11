#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable or disable a satellite for this constellation.
    ///
    /// Name    Type   Description
    /// ------- ------ ------------------------------------------------------------------------------------------------------
    /// System  string The satellite's constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId    int    The satellite's SV ID (use 0 for all SVs).
    /// Enabled bool   The satellite will be present/absent from the constellation
    ///

    class EnableSV;
    typedef std::shared_ptr<EnableSV> EnableSVPtr;
    
    
    class EnableSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSV();

      EnableSV(const std::string& system, int svId, bool enabled);

      static EnableSVPtr create(const std::string& system, int svId, bool enabled);
      static EnableSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

