#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the SISA(E1,E5b) index of a Galileo satellite
    ///
    /// Name  Type Description
    /// ----- ---- -------------------
    /// SvId  int  The satellite SV ID
    /// Sisai int  SISA index.
    ///

    class SetGalileoSisaE1E5bIndexForSV;
    typedef std::shared_ptr<SetGalileoSisaE1E5bIndexForSV> SetGalileoSisaE1E5bIndexForSVPtr;
    
    
    class SetGalileoSisaE1E5bIndexForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGalileoSisaE1E5bIndexForSV();

      SetGalileoSisaE1E5bIndexForSV(int svId, int sisai);
  
      static SetGalileoSisaE1E5bIndexForSVPtr create(int svId, int sisai);
      static SetGalileoSisaE1E5bIndexForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** sisai ****
      int sisai() const;
      void setSisai(int sisai);
    };
  }
}

