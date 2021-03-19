#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetGalileoSisaE1E5aIndex is deprecated since 21.3. You may use SetGalileoSisaE1E5aIndexForSV.
    /// 
    /// Set the SISA(E1,E5a) index of a Galileo satellite
    ///
    /// Name  Type Description
    /// ----- ---- -----------------
    /// Prn   int  The satellite PRN
    /// Sisai int  SISA index.
    ///

    class SetGalileoSisaE1E5aIndex;
    typedef std::shared_ptr<SetGalileoSisaE1E5aIndex> SetGalileoSisaE1E5aIndexPtr;
    
    
    class SetGalileoSisaE1E5aIndex : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGalileoSisaE1E5aIndex();

      SetGalileoSisaE1E5aIndex(int prn, int sisai);
  
      static SetGalileoSisaE1E5aIndexPtr create(int prn, int sisai);
      static SetGalileoSisaE1E5aIndexPtr dynamicCast(CommandBasePtr ptr);
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

