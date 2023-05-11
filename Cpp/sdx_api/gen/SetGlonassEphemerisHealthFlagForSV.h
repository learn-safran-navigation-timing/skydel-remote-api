#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GLONASS satellite Ephemeris Health Flag Bn(ln)
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------
    /// SvId   int  The satellite's SV ID 1..24
    /// Health bool Status, false = OK, true = Malfunction
    ///

    class SetGlonassEphemerisHealthFlagForSV;
    typedef std::shared_ptr<SetGlonassEphemerisHealthFlagForSV> SetGlonassEphemerisHealthFlagForSVPtr;
    
    
    class SetGlonassEphemerisHealthFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGlonassEphemerisHealthFlagForSV();

      SetGlonassEphemerisHealthFlagForSV(int svId, bool health);

      static SetGlonassEphemerisHealthFlagForSVPtr create(int svId, bool health);
      static SetGlonassEphemerisHealthFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
    
  }
}

