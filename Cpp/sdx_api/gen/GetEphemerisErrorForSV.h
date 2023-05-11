#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the satellite ephemeris error.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------
    /// System string "GPS", "Galileo", "GLONASS", "BeiDou", "QZSS" or "NavIC"
    /// SvId   int    Satellite SV ID.
    ///

    class GetEphemerisErrorForSV;
    typedef std::shared_ptr<GetEphemerisErrorForSV> GetEphemerisErrorForSVPtr;
    
    
    class GetEphemerisErrorForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetEphemerisErrorForSV();

      GetEphemerisErrorForSV(const std::string& system, int svId);

      static GetEphemerisErrorForSVPtr create(const std::string& system, int svId);
      static GetEphemerisErrorForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

