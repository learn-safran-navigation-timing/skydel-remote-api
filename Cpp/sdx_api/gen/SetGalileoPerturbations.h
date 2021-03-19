#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GalileoPerturbations is deprecated since 21.3. You may use Perturbations.
    /// 
    /// Set GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------
    /// Prn  int    Satellite PRN number 1..36
    /// Crs  double Crs (meter)
    /// Crc  double Crc (meter)
    /// Cis  double Crs (rad)
    /// Cic  double Crc (rad)
    /// Cus  double Cus (rad)
    /// Cuc  double Cuc (rad)
    ///

    class SetGalileoPerturbations;
    typedef std::shared_ptr<SetGalileoPerturbations> SetGalileoPerturbationsPtr;
    
    
    class SetGalileoPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGalileoPerturbations();

      SetGalileoPerturbations(int prn, double crs, double crc, double cis, double cic, double cus, double cuc);
  
      static SetGalileoPerturbationsPtr create(int prn, double crs, double crc, double cis, double cic, double cus, double cuc);
      static SetGalileoPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** crs ****
      double crs() const;
      void setCrs(double crs);


      // **** crc ****
      double crc() const;
      void setCrc(double crc);


      // **** cis ****
      double cis() const;
      void setCis(double cis);


      // **** cic ****
      double cic() const;
      void setCic(double cic);


      // **** cus ****
      double cus() const;
      void setCus(double cus);


      // **** cuc ****
      double cuc() const;
      void setCuc(double cuc);
    };
  }
}

