#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGalileoSisaE1E5bIndex is deprecated since 21.3. You may use SetGalileoSisaE1E5bIndexForSV.
    /// 
    /// Set the SISA(E1,E5b) index of a Galileo satellite
    ///
    /// Name  Type Description
    /// ----- ---- -----------------
    /// Prn   int  The satellite PRN
    /// Sisai int  SISA index.
    ///

    class SetGalileoSisaE1E5bIndex;
    typedef std::shared_ptr<SetGalileoSisaE1E5bIndex> SetGalileoSisaE1E5bIndexPtr;
    
    
    class SetGalileoSisaE1E5bIndex : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGalileoSisaE1E5bIndex();

      SetGalileoSisaE1E5bIndex(int prn, int sisai);
  
      static SetGalileoSisaE1E5bIndexPtr create(int prn, int sisai);
      static SetGalileoSisaE1E5bIndexPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** sisai ****
      int sisai() const;
      void setSisai(int sisai);
    };
  }
}

